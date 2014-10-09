#include "cv.h"
//#include "cxcore.h"
#include "highgui.h"
#include "math.h"
#include <iostream>
//#include <stdioj.h>
#include <string.h>
#include <conio.h>
#include <sstream>
#include "cvblob/cvblob.cpp"
#include "cvblob/cvblob.h"
#include "cvblob/cvlabel.cpp"
#include "Tserial.cpp"
#ifdef __BORLANDC__
#pragma hdrstop            // borland specific
#include <condefs.h>
#pragma argsused
USEUNIT("Tserial.cpp");
#endif
#define time 1
#define redhuehigh 15
#define bluehuehigh 00
#define greenhuehigh 80
#define yellowhuehigh 49
#define yellowhuelow 21
#define redhuelow 178
#define bluehuelow 00
#define greenhuelow 50
#define pinkhuelow 150
#define pinkhuehigh 178

#define redsat 100//185-220
#define bluesat 00
#define greensat 75
#define yellowsat 30
#define pinksat 75
#define yellowvalue 200 //130
#define redvalue 125//180-220
#define bluevalue 00
#define greenvalue 100
#define pinkvalue 200

#define whitesat 50
#define blackval 75

#define actual_distance2 2.5  //in cm   distnace2: d b/w centroid of bot to centroid of pink_front
#define actual_width 20 //cm    width of actual bot set at 10 /20 ?
#define error_ratio .76 // two third (15-4)/15
                        // now (10-2)/10
#define error_ratio_p  0.8 //pit
#define error_distance 12 //in cm, (9-2)+5 taking minimum distance when ball is in line of sight
#define error_distance_p 10 //in cm 7.5*1.4+5, taking approach along corner
#define speed_limit 30//in cm, distance less than which to go slow

#define servo_time 1000 //in ms

#define shift_x 18
#define shift_y 7

using namespace std;
using namespace cvb;

IplImage* input;
IplImage* frame;
IplImage* red_filter;
IplImage* blue_filter;      //front bot
IplImage* black_filter;     // may become yellow also
IplImage* green_filter;
IplImage* white_filter;
IplImage* yellow_filter;
IplImage* pink_filter;
IplImage* boundary;
IplImage* ball_track;

struct coordinate
{
    int x,y;
}centroid_pit,corner_pit, centroid_ball , centroid_bot_pinkf, centroid_bot_yellowb;
int ball_size, minx_white,minx_green,maxx_green,miny_green,maxy_green;
double distance1,angle,scale, distance2,width,permissible_angle;//bot size left
bool within_error_angle, grabbed=false,within_error_distance,servo_cmnd,go_pit=false, present=false;
Tserial *com;
double distance1_p,angle_p,permissible_angle_p;
bool within_error_angle_p,within_error_distance_p,go_back,parallax_corrected=false;
void static_boundary();
void process_image();
void filter_image();    // simultaneously filter all
void blob_image();
void calculate();
void motor_control();   //rotate, move
void error_limit();
void grab_ball();
void go_to_pit();
void start_orient();

void process_pit();
void pit_calculate();
void pit_error_limit();
void pit_motor_control();

int Send(char head);

bool calculate2(int x, int y);

//=================================================================================================================================================

int max2(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int min2(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

void my_mouse_callback( int event, int x, int y, int flags, void* param )
{
   int height, width;
   height=frame->height;
   width=frame->width;
   uchar *pimage   =  (uchar*)frame->imageData;
   int r=pimage[y*frame->widthStep + x*frame->nChannels+2];
   int g=pimage[y*frame->widthStep + x*frame->nChannels+1];
   int b=pimage[y*frame->widthStep + x*frame->nChannels+0];

   printf("\nx=%d(%d)\t y=%d(%d)\t\tr=%d \tg=%d \tb=%d\n",x,width,y,height,r,g,b);
}

void display_screen()
{
    cvNamedWindow("img");
    //cvShowImage("img",input);
    cvShowImage("img",frame);
    cvSetMouseCallback("img", my_mouse_callback, NULL);
    cvWaitKey(0);
    cvDestroyWindow( "img" );

}

int main()
{
    int i;
    //com = new Tserial();
    //com->connect("COM1", 9600, spNONE);
    CvCapture *capture=cvCreateCameraCapture(0);        //initiate camera
    for(i=0;i<100000000;i++);//starting camera takes some time and we can take any frame only after camera starts or frame value will be  black

    if(capture!=NULL)       //camera has begun starting itself
    {
                     frame=cvQueryFrame(capture);//take current image in camera and give it to frame pointer
                     //cvSaveImage("arena.jpg",frame);
                     input=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,3);
                     ball_track=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
                     int j;
                     /*for(i=0;i<input->height;i++)
                        for(j=0;j<input->width;j++)
                        {
                            ball_track->imageData[i*input->width + j]=0;
                        }*/
                     cvCvtColor(frame,input,CV_BGR2HSV);
                     //cvNamedWindow("img");
                     //cvShowImage("img",input);
                     //cvShowImage("img",frame);
                     //cvWaitKey(0);
                     //cvDestroyWindow( "img" );
                     filter_image();
                     static_boundary();
                     cvReleaseImage( &red_filter );
                        cvReleaseImage( &black_filter );
                        cvReleaseImage( &white_filter );
                        cvReleaseImage( &blue_filter );
                        cvReleaseImage( &green_filter );
                        cvReleaseImage( &yellow_filter );
                        cvReleaseImage( &pink_filter );
                     while(1)
                     {
                        frame=cvQueryFrame(capture);
                        input=cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,3);
                        cvCvtColor(frame,input,CV_BGR2HSV);//Note:  output image must be created
                        cvWaitKey(time);
                        process_image();
                        cvReleaseImage( &red_filter );
                        cvReleaseImage( &black_filter );
                        cvReleaseImage( &white_filter );
                        cvReleaseImage( &blue_filter );
                        cvReleaseImage( &green_filter );
                        cvReleaseImage( &yellow_filter );
                        cvReleaseImage( &pink_filter );
                        cvReleaseImage( &input );
                        cvReleaseImage( &boundary );
                        parallax_corrected=false;
                        //cvSaveImage("ball_track.jpg",ball_track);

                     }
                     //cvSaveImage("ball_track.jpg",ball_track);
                     cvReleaseImage( &input );
                     cvReleaseImage( &frame );
                     cvReleaseImage( &ball_track );
                     cvReleaseCapture(&capture);
    }
    //com->disconnect();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

void filter_image()
{
    int h,s,v,i,j;

    red_filter=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);
    blue_filter=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);
    green_filter=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);
    black_filter=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);
    white_filter=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);
    yellow_filter=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);
    pink_filter=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);
    boundary=cvCreateImage(cvSize(input->width, input->height ),input->depth, 1);

     uchar *pinput   =  (uchar*)input->imageData;//saving data pointer of input image as pinput

    for(i=0;i<input->height;i++)
            for(j=0;j<input->width;j++)
            {
                h=pinput[i*input->widthStep + j*input->nChannels + 0];
                s=pinput[i*input->widthStep + j*input->nChannels + 1];
                v=pinput[i*input->widthStep + j*input->nChannels + 2];
                if(v<=blackval)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=255;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=0;
                }
                else if(s<=whitesat)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=255;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=0;
                }
                else if(((h>=redhuelow && h<=190) || h<=redhuehigh) && s>=redsat && v>=redvalue)
                {
                   red_filter->imageData[i*input->width + j]=255;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=0;
                }
                else if(h>=bluehuelow && h<=bluehuehigh && s>=bluesat && v>=bluevalue)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=255;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=0;
                }
                else if(h>=greenhuelow && h<=greenhuehigh && s>=greensat && v>=greenvalue)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=255;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=0;
                }
                else if(h>=yellowhuelow && h<=yellowhuehigh && s>=yellowsat && v>=yellowvalue)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=255;
                   pink_filter->imageData[i*input->width + j]=0;
                }
                else if(h>=pinkhuelow && h<=pinkhuehigh && s>=pinksat && v>=pinkvalue)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=255;
                }
                //printf("%d\n",white_filter->imageData[i*input->width + j]);
            }

    miny_green=108;
maxy_green=371;
    //printf("final:%d %d\n",t1,t2);
    //char a=getch();
    for(i=0;i<input->height;i++)
            for(j=0;j<input->width;j++)
            {
                if(i<miny_green || i>maxy_green)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=0;
                }
            }

minx_green=9;
maxx_green=528;

    //printf("final:%d %d\n",t1,t2);
    for(i=0;i<input->height;i++)
            for(j=0;j<input->width;j++)
            {
                if(j<minx_green || j>maxx_green)
                {
                   red_filter->imageData[i*input->width + j]=0;
                   blue_filter->imageData[i*input->width + j]=0;
                   green_filter->imageData[i*input->width + j]=0;
                   black_filter->imageData[i*input->width + j]=0;
                   white_filter->imageData[i*input->width + j]=0;
                   yellow_filter->imageData[i*input->width + j]=0;
                   pink_filter->imageData[i*input->width + j]=0;
                }
            }

   for(i=0;i<input->height;i++)
    {
        for(j=0;j<input->width;j++)
        {
            //if(pink_filter->imageData[i*input->width + j]!=0)
                boundary->imageData[i*input->width + j]=0; //255 to keep pink
            //else
            //    boundary->imageData[i*input->width + j]=0;
        }
    }
            cvMorphologyEx(red_filter,red_filter, NULL,NULL, CV_MOP_OPEN, 1);//noise removal from binary image
            cvMorphologyEx(blue_filter,blue_filter, NULL,NULL, CV_MOP_OPEN, 1);//noise removal from binary image
            cvMorphologyEx(green_filter,green_filter, NULL,NULL, CV_MOP_OPEN, 1);//noise removal from binary image
            cvMorphologyEx(black_filter,black_filter, NULL,NULL, CV_MOP_OPEN, 1);//noise removal from binary image
            cvMorphologyEx(white_filter,white_filter, NULL,NULL, CV_MOP_OPEN, 1);//noise removal from binary image
            cvMorphologyEx(yellow_filter,yellow_filter, NULL,NULL, CV_MOP_OPEN, 1);//noise removal from binary image
            cvMorphologyEx(pink_filter,pink_filter, NULL,NULL, CV_MOP_OPEN, 1);
            //cvMorphologyEx(boundary,boundary, NULL,NULL, CV_MOP_OPEN, 1);

            /*cvNamedWindow("red_filter");
            cvShowImage("red_filter",red_filter);
            cvNamedWindow("blue_filter");
            cvShowImage("blue_filter",blue_filter);
            cvNamedWindow("green_filter");
            cvShowImage("green_filter",green_filter);
            cvNamedWindow("black_filter");
            cvShowImage("black_filter",black_filter);
            cvNamedWindow("white_filter");
            cvShowImage("white_filter",white_filter);
            cvNamedWindow("yellow_filter");
            cvShowImage("yellow_filter",yellow_filter);
            cvNamedWindow("pink_filter");
            cvShowImage("pink_filter",pink_filter);
            cvNamedWindow("boundary");
            cvShowImage("boundary",boundary);
            cvWaitKey(0);
            cvDestroyWindow("red_filter");
            cvDestroyWindow("blue_filter");
            cvDestroyWindow("green_filter");
            cvDestroyWindow("black_filter");
            cvDestroyWindow("white_filter");
            cvDestroyWindow("yellow_filter");
            cvDestroyWindow("pink_filter");
            cvDestroyWindow("boundary");*/

            //cvSaveImage("pink.jpg",pink_filter);
            //cvSaveImage("yellow.jpg",yellow_filter);
            /*cvSaveImage("red.jpg",red_filter);
            cvSaveImage("green.jpg",green_filter);
            cvSaveImage("black.jpg",black_filter);
            cvSaveImage("white.jpg",white_filter);*/

            // *******note : here we may also use fill holes using flood_fill function
            // ******* we may also increase no. of iterations
}

//Here we can adjust centroid of pit according to image given...... (xmin based identification)

void static_boundary()
{
    /*int i,j;
    uchar *pinput   =  (uchar*)white_filter->imageData;
    for(i=0;i< white_filter->height;i++)
        for(j=0;j<white_filter->width;j++)
        {
            if(pinput[i*(white_filter->widthstep) + j]==1)

        }*/
    //printf("enter blob part\n");
    int max1=0,max2=0,max;
    CvBlobs blobs;
    CvBlobs::const_iterator n1;
    CvBlobs::const_iterator n2;
    CvBlobs::const_iterator n;
    CvBlobs::const_iterator it;
    //printf("blob variables created\n");
    IplImage* temp=cvCreateImage(cvGetSize(black_filter),IPL_DEPTH_LABEL,1); //note the depth type,keep it that way... 32 bit
    cvLabel(black_filter,temp,blobs);//get the inf about all the blobs on the image
    //printf("blobs created\n");
    for (it=blobs.begin(); it!=blobs.end(); ++it) //finds the blob with max area most probably the hand
       {
           if(it->second->area>max1)
             {
                max2=max1;
                n2=n1;
                max1=it->second->area;
                n1=it;
              }
            else if(it->second->area>max2)
            {
                max2=it->second->area;
                n2=it;
            }
       }
    if(n1->second->centroid.x<n2->second->centroid.x)
    {
        n=n1;
    }
    else
    {
        n=n2;
    }
    //printf("found max\n");
centroid_pit.x=22; //assinging the centroid . this is also used by other fxns
centroid_pit.y=127;
    corner_pit.x=n->second->minx;
    corner_pit.y=n->second->miny;
    cvReleaseBlobs(blobs);
    cvReleaseImage(&temp);
    printf("centroid pit x:%d centroid pit y:%d\n",centroid_pit.x,centroid_pit.y);
    max=0;
    temp=cvCreateImage(cvGetSize(white_filter),IPL_DEPTH_LABEL,1);
    cvLabel(white_filter,temp,blobs);//get the inf about all the blobs on the image
    //printf("blobs for white created\n");
    for (it=blobs.begin(); it!=blobs.end(); ++it) //finds the blob with max area most probably the hand
       {
           if(it->second->area>max)
             {
                max=it->second->area;
                n=it;
              }
       }
    minx_white=428;
    cvReleaseBlobs(blobs);
    cvReleaseImage(&temp);
    printf("min x white:%d\n",minx_white);

    //display_screen();
}

void blob_image()
{
    int max=0;  //second=0
    //printf("enter blob\n");
    CvBlobs blobs;
    CvBlobs::const_iterator n;
    CvBlobs::const_iterator it;
    int cnt=0;
    IplImage* temp=cvCreateImage(cvGetSize(red_filter),IPL_DEPTH_LABEL,1); //note the depth type... 32 bit
    //printf("enter blob chk2\n");
    cvLabel(red_filter,temp,blobs);//get the inf about all the blobs on the image
    for (it=blobs.begin(); it!=blobs.end(); ++it) //finds the blob with max area
       {
           if(it->second->area>max)
             {
                max=it->second->area;
                n=it;
              }
            cnt++;
       }
    if(cnt!=0  && n->second->area>1)
    {
        centroid_ball.x=n->second->centroid.x; //assinging the centroid . this is also used by other fxns
        centroid_ball.y=n->second->centroid.y;
        ball_size=(centroid_ball.x)-(n->second->minx);
        ball_track->imageData[centroid_ball.y*input->width + centroid_ball.x]=255;
        present=true;
        //printf("ball x:%d\tball y:%d\n",centroid_ball.x,centroid_ball.y);
    }
    else
    {
        present=false;
        //printf("ball not present\n");
    }
    //printf("enter blob chk 5\n");
    cvReleaseBlobs(blobs);
    cvReleaseImage(&temp);

    //printf("ball part done\n");
    //printf("ball x:%d ball y:%d\n",centroid_ball.x,centroid_ball.y);
    //display_screen();


    max=0;
    cnt=0;
    temp=cvCreateImage(cvGetSize(pink_filter),IPL_DEPTH_LABEL,1);
    cvLabel(pink_filter,temp,blobs);//get the inf about all the blobs on the image
    for (it=blobs.begin(); it!=blobs.end(); ++it) //finds the blob with max area most probably the hand
       {
           if(it->second->area>max)
             {
                max=it->second->area;
                n=it;
              }
            cnt++;
       }
    if(cnt!=0)
    {
        centroid_bot_pinkf.x=n->second->centroid.x; //assinging the centroid . this is also used by other fxns
        centroid_bot_pinkf.y=n->second->centroid.y;
    }
    else
    {
        present=false;
    }
    cvReleaseBlobs(blobs);
    cvReleaseImage(&temp);
    //display_screen();
    max=0;
    cnt=0;
    temp=cvCreateImage(cvGetSize(yellow_filter),IPL_DEPTH_LABEL,1);
    cvLabel(yellow_filter,temp,blobs);//get the inf about all the blobs on the image
    for (it=blobs.begin(); it!=blobs.end(); ++it) //finds the blob with max area most probably the hand
       {
           if(it->second->area>max)
             {
                max=it->second->area;
                n=it;
              }
            cnt++;
       }
    if(cnt!=0)
    {
        centroid_bot_yellowb.x=n->second->centroid.x; //assinging the centroid . this is also used by other fxns
        centroid_bot_yellowb.y=n->second->centroid.y;
    }
    else
    {
        present=false;
    }
    cvReleaseBlobs(blobs);
    cvReleaseImage(&temp);

    if(parallax_corrected==false)
    {
        int correct_x=0,correct_y=0;
        int centre_x=(minx_green+maxx_green)/2;
        int arena_widthby2=maxx_green-centre_x;
        int centre_y=(miny_green+maxy_green)/2;
        int arena_heightby2=maxy_green-centre_y;
        correct_x=(shift_x*((abs(centroid_bot_pinkf.x-centre_x)*10)/(arena_widthby2))/10);
        correct_y=(shift_y*((abs(centroid_bot_pinkf.y-centre_y)*10)/(arena_heightby2))/10);
        //printf("correction x:%d\tcorrection y:%d\n",correct_x,correct_y);
        int i,j;
        if(centroid_bot_pinkf.x<centre_x)
        {
            for(i=0;i<input->height;i++)
            {
                for(j=input->width-1;j>=0;j--)
                {
                    if(j>correct_x)
                    {
                        yellow_filter->imageData[i*input->width + j]=yellow_filter->imageData[i*input->width + (j-correct_x)];
                        pink_filter->imageData[i*input->width + j]=pink_filter->imageData[i*input->width + (j-correct_x)];
                    }
                    else
                    {
                        yellow_filter->imageData[i*input->width + j]=0;
                        pink_filter->imageData[i*input->width + j]=0;
                    }
                }

            }
        }
        else
        {
            for(i=0;i<input->height;i++)
            {
                for(j=0;j<input->width;j++)
                {
                    if(j<(input->width-correct_x))
                    {
                        yellow_filter->imageData[i*input->width + j]=yellow_filter->imageData[i*input->width + (j+correct_x)];
                        pink_filter->imageData[i*input->width + j]=pink_filter->imageData[i*input->width + (j+correct_x)];
                    }
                    else
                    {
                        yellow_filter->imageData[i*input->width + j]=0;
                        pink_filter->imageData[i*input->width + j]=0;
                    }
                }
            }
        }
        if(centroid_bot_pinkf.y<centre_y)
        {
            for(i=input->height-1;i>=0;i--)
            {
                for(j=0;j<input->width;j++)
                {
                    if(i>correct_y)
                    {
                        yellow_filter->imageData[i*input->width + j]=yellow_filter->imageData[(i-correct_y)*input->width + (j)];
                        pink_filter->imageData[i*input->width + j]=pink_filter->imageData[(i-correct_y)*input->width + (j)];
                    }
                    else
                    {
                        yellow_filter->imageData[i*input->width + j]=0;
                        pink_filter->imageData[i*input->width + j]=0;
                    }
                }

            }
        }
        else
        {
            for(i=0;i<input->height;i++)
            {
                for(j=0;j<input->width;j++)
                {
                    if(i<(input->height-correct_y))
                    {
                        yellow_filter->imageData[i*input->width + j]=yellow_filter->imageData[(i+correct_y)*input->width + (j)];
                        pink_filter->imageData[i*input->width + j]=pink_filter->imageData[(i+correct_y)*input->width + (j)];
                    }
                    else
                    {
                        yellow_filter->imageData[i*input->width + j]=0;
                        pink_filter->imageData[i*input->width + j]=0;
                    }
                }
            }
        }
        parallax_corrected=true;
        blob_image();
    }
    //if(parallax_corrected)
    //    parallax_corrected=false;

    //printf("ball x:%d ball y:%d\npink x:%d pink y:%d\nyellow x:%d yellow y:%d\n",centroid_ball.x,centroid_ball.y,centroid_bot_pinkf.x,centroid_bot_pinkf.y,centroid_bot_yellowb.x,centroid_bot_yellowb.y);
    //display_screen();
    int i,j;
    go_back=false;
    /*cvNamedWindow("boundary1");
    cvShowImage("boundary1",boundary);
    cvWaitKey(0);*/
    calculate2(0,0);    //done to set scale
    //printf("i:%d::%d\n",max2(centroid_bot_pinkf.y-scale*actual_width,0),min2(input->height,centroid_bot_pinkf.y+scale*actual_width));
    //printf("j:%d::%d\n",max2(centroid_bot_pinkf.x-scale*actual_width,0),min2(input->width,centroid_bot_pinkf.x+scale*actual_width));
    for(i=max2(centroid_bot_pinkf.y-scale*actual_width*0.75,0);i<min2(input->height,centroid_bot_pinkf.y+scale*actual_width*0.75);i++)
    {
        for(j=max2(centroid_bot_pinkf.x-scale*actual_width*0.75,0);j<min2(input->width,centroid_bot_pinkf.x+scale*actual_width*0.75);j++)
        {
            if(calculate2(j,i))
                boundary->imageData[i*input->width + j]=255;
            if(boundary->imageData[i*input->width + j]!=0)
            {
                if(j<minx_green)
                {
                    if(centroid_bot_pinkf.x<centroid_bot_yellowb.x)
                        go_back=true;
                }
                if(j>maxx_green)
                {
                    if(centroid_bot_pinkf.x>centroid_bot_yellowb.x)
                        go_back=true;
                }
                if(i<miny_green)
                {
                    if(centroid_bot_pinkf.y<centroid_bot_yellowb.y)
                        go_back=true;
                }
                if(i>maxy_green)
                {
                    if(centroid_bot_pinkf.y>centroid_bot_yellowb.y)
                        go_back=true;
                }

            }
            //if(i==miny_green || i==maxy_green || j==minx_green || j==maxx_green)
            //   boundary->imageData[i*input->width + j]=0;
        }
    }
    for(i=0;i<input->height;i++)
    {
        for(j=0;j<input->width;j++)
        {
            if(i==miny_green || i==maxy_green || j==minx_green || j==maxx_green)
               boundary->imageData[i*input->width + j]=255;       // do 255 to display boundary
        }
    }

  /*cvNamedWindow("yellow_filter");
            cvShowImage("yellow_filter",yellow_filter);
            cvNamedWindow("pink_filter");
            cvShowImage("pink_filter",pink_filter);
           // cvWaitKey(0);
    cvNamedWindow("boundary");
    cvShowImage("boundary",boundary);*/
    //cvWaitKey(0);

}

void calculate()
{
    float centrex,centrey,x1,y1,x2,y2,sine,d1,d2;
    centrex=(centroid_bot_pinkf.x+centroid_bot_yellowb.x)/2;
    centrey=(centroid_bot_pinkf.y+centroid_bot_yellowb.y)/2;
    distance1=sqrt((centroid_ball.x-centrex)*(centroid_ball.x-centrex)+(centroid_ball.y-centrey)*(centroid_ball.y-centrey));
    x1=centroid_ball.x-centrex;
    y1=centroid_ball.y-centrey;
    x2=centroid_bot_pinkf.x-centrex;
    y2=centroid_bot_pinkf.y-centrey;
    distance2=sqrt(x2*x2 + y2*y2);
    sine=(-x2*y1 + x1*y2)/(distance1*distance2);    // positive means rotate left, else right
    //printf("sine:%lf\n",sine);
    angle=asin(sine)*180/3.142;
    //printf("angle:%lf\n",angle);
    //printf("D:%lf\n",distance1/scale);
    //while(1);
    d1=sqrt((centroid_ball.x-centroid_bot_pinkf.x)*(centroid_ball.x-centroid_bot_pinkf.x) + (centroid_ball.y-centroid_bot_pinkf.y)*(centroid_ball.y-centroid_bot_pinkf.y));
    d2=sqrt((centroid_ball.x-centroid_bot_yellowb.x)*(centroid_ball.x-centroid_bot_yellowb.x) + (centroid_ball.y-centroid_bot_yellowb.y)*(centroid_ball.y-centroid_bot_yellowb.y));
    //printf("d1:%lf\td2:%lf\n",d1,d2);
    if(d2<d1 && angle>0)
        angle=180-angle;
    else if(d2<d1 && angle<0)
        angle=-180-angle;
    //printf("angle:%lf\tdistance:%lf\n",angle,distance1);
    //while(1);
}

void error_limit()  //takes distance as input and gives permissimble angle as ouput
{
    scale=distance2/actual_distance2;   //pixel per cm
    //printf("scale:%lf\n",scale);
    width=scale*actual_width;   // in pixels
    if(((width/2)*error_ratio)>distance1)
        permissible_angle=90;
    else
        permissible_angle=asin(((width/2)*error_ratio)/distance1)*180/3.142;
    permissible_angle=abs(permissible_angle);
    //printf("permit angle:%lf\n",permissible_angle);
    if(abs(angle)<permissible_angle)
        within_error_angle=true;
    else
        within_error_angle=false;
    if(distance1<= scale*error_distance)
        within_error_distance=true;
    else
        within_error_distance=false;

    if(within_error_angle)
        if(within_error_distance)
            printf("within angle and distance\n");
        else
            printf("within angle but not within distance\n");
    else
        if(within_error_distance)
            printf("not within angle but within distance\n");
        else
            printf("not within angle and not within distance\n");
    //while(1);
}

void  motor_control()   // takes input as angle(-180 to 180) & distance & permissible angle
{
    if(go_back)
    {
        printf("B\n");
        Send('B');
        return;
    }

    /*if(grabbed && !present)
    {
        go_pit=true;
        grabbed=false;
        printf("ball grabbed\n");
        return;
    }*/
    if(within_error_angle)
    {
        if(within_error_distance)
        {
            grab_ball();
        }
        else
        {
            if(grabbed)
            {
                grabbed=false;
                printf("servo up\n");
                Send('L');
                Sleep(servo_time);
            }
            if(distance1<speed_limit*scale)
            {
                printf("S\n");
                //while(1);
                Send('S');
            }
            else
            {
                printf("F\n");
                //while(1);
                Send('F');
            }
        }
    }
    else
    {
            if(grabbed)
            {
                grabbed=false;
                printf("servo up\n");
                Send('L');
                Sleep(servo_time);
            }
        if(abs(angle)<60)
        {
            if(distance1>scale*40  && abs(angle)<30)
            {
                    printf("F\n");
                    Send('F');
            }
            else
            {
            if(angle>0)
            {

                printf("a\n");
                //while(1);
                //Send('a');
                Send('b');
            }
            else
            {
                printf("f\n");
                //while(1);
                //Send('f');
                Send('e');
            }
            }
        }
        else if(abs(angle)<120)
        {
            if(angle>0)
            {
                printf("b\n");
                //while(1);
                Send('b');
            }
            else
            {
                printf("e\n");
                //while(1);
                Send('e');
            }
        }
        else
        {
            if(angle>0)
            {
                printf("c\n");
                //while(1);
                Send('c');
            }
            else
            {
                printf("d\n");
                //while(1);
                Send('d');
            }
        }
    }
}

void grab_ball()
{
    if(grabbed==false)
    {
        printf("servo down\n");
        Send('p');
        Send('G');
        Sleep(servo_time);
        grabbed=true;
    }
    else
    {
        go_pit=true;
        grabbed=false;
        printf("ball grabbed\n");
        //Send('x');
    }
}

void pit_calculate()
{
    float centrex,centrey,x1,y1,x2,y2,sine,d1,d2;
    centrex=(centroid_bot_pinkf.x+centroid_bot_yellowb.x)/2;
    centrey=(centroid_bot_pinkf.y+centroid_bot_yellowb.y)/2;
    distance1_p=sqrt((centroid_pit.x-centrex)*(centroid_pit.x-centrex)+(centroid_pit.y-centrey)*(centroid_pit.y-centrey));
    x1=centroid_pit.x-centrex;
    y1=centroid_pit.y-centrey;
    x2=centroid_bot_pinkf.x-centrex;
    y2=centroid_bot_pinkf.y-centrey;
    distance2=sqrt(x2*x2 + y2*y2);
    sine=(-x2*y1 + x1*y2)/(distance1_p*distance2);    // positive means rotate left, else right
    angle_p=asin(sine)*180/3.142;
    d1=sqrt((centroid_pit.x-centroid_bot_pinkf.x)*(centroid_pit.x-centroid_bot_pinkf.x) + (centroid_pit.y-centroid_bot_pinkf.y)*(centroid_pit.y-centroid_bot_pinkf.y));
    d2=sqrt((centroid_pit.x-centroid_bot_yellowb.x)*(centroid_pit.x-centroid_bot_yellowb.x) + (centroid_pit.y-centroid_bot_yellowb.y)*(centroid_pit.y-centroid_bot_yellowb.y));
    if(d2<d1 && angle_p>0)
        angle_p=180-angle_p;
    else if(d2<d1 && angle_p<0)
        angle_p=-180-angle_p;
}

void pit_error_limit()
{
    width=scale*actual_width;   // in pixels
    if(((width/2)*error_ratio_p)>distance1_p)
        permissible_angle_p=90;
    else
        permissible_angle_p=asin(((width/2)*error_ratio_p)/distance1_p)*180/3.142;
    permissible_angle_p=abs(permissible_angle_p);
    if(abs(angle_p)<permissible_angle_p)
        within_error_angle_p=true;
    else
        within_error_angle_p=false;
    if(distance1_p<= scale*error_distance_p)
        within_error_distance_p=true;
    else
        within_error_distance_p=false;
    if(within_error_angle_p)
        if(within_error_distance_p)
            printf("within angle and distance\n");
        else
            printf("within angle but not within distance\n");
    else
        if(within_error_distance_p)
            printf("not within angle but within distance\n");
        else
            printf("not within angle and not within distance\n");
}

void  pit_motor_control()   // takes input as angle(-180 to 180) & distance & permissible angle
{
   /*if(go_back)
    {
        Send('B');
        printf("B\n");
        return;
    }

        if(within_error_distance_p && within_error_angle_p)
        {
            Send('p');
            Send('L');
            printf("servo up\n");
            Sleep(servo_time);
            go_pit=false;
        }
        else if(distance1_p<scale*error_distance_p*1.5 && within_error_angle_p)
        {
            Send('L');
            printf("servo up\n");
            //Sleep(servo_time);
        }
        else if(within_error_angle_p)
        {
            if(distance1_p<speed_limit*scale)
            {
                Send('S');
                printf("S\n");
            }
            else
            {
                Send('F');
                printf("F\n");
            }
        }
    else
    {
        if(abs(angle_p)<60)
        {
            if(distance1_p>scale*40  && abs(angle_p)<30)
            {
                    printf("F\n");
                    Send('F');
            }
            else
            {
            if(angle_p>0)
            {
                Send('a');
                printf("a\n");
            }
            else
            {
                Send('f');
                printf("f\n");
            }
            }
        }
        else if(abs(angle_p)<120)
        {
            if(angle_p>0)
            {
                Send('b');
                printf("b\n");
            }
            else
            {
                Send('e');
                printf("e\n");
            }
        }
        else
        {
            if(angle_p>0)
            {
                Send('c');
                printf("c\n");
            }
            else
            {
                Send('d');
                printf("d\n");
            }
        }
    }*/

        if(go_back)
        {
        Send('B');
        printf("B\n");
        return;
        }
        //if(distance1_p<17.5*scale && distance1_p>10*scale)
        //{
        //    Send('S');
        //}

        if(within_error_distance_p)
        {
            Send('p');
            Send('L');
            printf("servo up\n");
            Sleep(servo_time);
            go_pit=false;
        }

        else if(distance1_p<scale*19 )
        {
            Send('L');
            printf("servo up\n");
            Send('S');
            //Sleep(servo_time);
        }

        else if(within_error_angle_p)
        {
            if(distance1_p<speed_limit*scale)
            {
                Send('S');
                printf("S\n");
            }
            else
            {
                Send('F');
                printf("F\n");
            }
        }


        else
        {
        if(abs(angle_p)<60)
        {
            if(distance1_p>scale*40  && abs(angle_p)<30)
            {
                    printf("F\n");
                    Send('F');
            }
            else
            {
            if(angle_p>0)
            {
                Send('a');
                printf("a\n");
            }
            else
            {
                Send('f');
                printf("f\n");
            }
            }
        }
        else if(abs(angle_p)<120)
        {
            if(angle_p>0)
            {
                Send('b');
                printf("b\n");
            }
            else
            {
                Send('e');
                printf("e\n");
            }
        }
        else
        {
            if(angle_p>0)
            {
                Send('c');
                printf("c\n");
            }
            else
            {
                Send('d');
                printf("d\n");
            }
        }
        }





}

void process_image()
{
    filter_image();
    blob_image();
    //char c2;
    //Sleep(100);
    //do{
    //c2=com->getChar();
    //}while(c2!='x');
   /* if(go_pit)
    {
        printf("go pit\n");
        pit_calculate();
        pit_error_limit();
        pit_motor_control();
    }*/
    if(grabbed && !present)     // done for the case : when servo down and bal not visible
    {
        go_pit=true;
        grabbed=false;
        printf("ball grabbed\n");
        return;
    }
    if(present && go_pit==false)
    {
        calculate();
        error_limit();
        motor_control();
    }
    else if(go_pit)             // remove condition
    {
         printf("go pit\n");
        pit_calculate();
        pit_error_limit();
        pit_motor_control();
    }
    if(!present)
    {
        printf("ball not present\n");
    }

}

int Send(char head)
{

   com = new Tserial();
   com->connect("COM1", 9600, spNONE);
   com->sendChar(head);
   //printf("head=%c\n",head);
   //com->sendChar(value);
   //printf("value=%d\n\n",value);
   com->disconnect();
    return 0;
}



bool calculate2(int x, int y)
{
    float centrex,centrey,x1,y1,x2,y2,sine,d1,d2,d3,angle1,permissible_angle1/*,x3,y3,distance3*/;
    centrex=(centroid_bot_pinkf.x+centroid_bot_yellowb.x)/2;
    centrey=(centroid_bot_pinkf.y+centroid_bot_yellowb.y)/2;
    d3=sqrt((x-centrex)*(x-centrex)+(y-centrey)*(y-centrey));
    x1=x-centrex;
    y1=y-centrey;
    x2=centroid_bot_pinkf.x-centrex;
    y2=centroid_bot_pinkf.y-centrey;
    //x3=centroid_bot_yellowb.x-centrex;
    //y3=centroid_bot_yellowb.y-centrey;

    distance2=sqrt(x2*x2 + y2*y2);
    //distance3=sqrt(x3*x3 + y3*y3);
    sine=(-x2*y1 + x1*y2)/(d3*distance2);    // positive means rotate left, else right

    angle1=asin(sine)*180/3.142;

    d1=sqrt((x-centroid_bot_pinkf.x)*(x-centroid_bot_pinkf.x) + (y-centroid_bot_pinkf.y)*(y-centroid_bot_pinkf.y));
    d2=sqrt((x-centroid_bot_yellowb.x)*(x-centroid_bot_yellowb.x) + (y-centroid_bot_yellowb.y)*(y-centroid_bot_yellowb.y));

    if(d2<d1 && angle1>=0)
        angle1=180-angle1;
    else if(d2<d1 && angle1<0)
        angle1=-180-angle1;

    scale=(distance2+distance2)/(2*actual_distance2);   //pixel per cm
    //printf("D:%lf\n",distance1/scale);
    //while(1);
    width=scale*actual_width;   // in pixels
    if((width/2)*0.8>d3)
        permissible_angle1=90;
    else
        permissible_angle1=asin(((float)width/2)*0.8/d3)*180/3.142;
    permissible_angle1=abs(permissible_angle1);
    /*if(!(abs(angle1)<permissible_angle1) && d3<= scale*15 && d1<d2)
    {
        //printf("angle1:%lf\tpermit:%lf\tsine:%lf\n",angle1,permissible_angle1,((float)width/2)/d3);
        //Sleep(50);
    }*/
    if(abs(angle1)<permissible_angle1 && d3<= scale*12.5)//error distance 15 is in cm
        return true;
    else
        return false;
}

/*
*p-stop
*S-slow forward
*F-fast forward
*a,b,c,d,e,f- anticlockwise from 12 o clock
*a-left speed 1
*b-left speed 2
*c-left speed 3
*d-right speed 3
*e-right speed 2
*f-right speed 1
*G-servo down
*L-servo up
*3>2>1
*/