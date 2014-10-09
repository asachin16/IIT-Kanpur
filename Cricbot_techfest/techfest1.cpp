#ifdef __BORLANDC__
#pragma hdrstop            // borland specific
#include <condefs.h>
#pragma argsused
USEUNIT("Tserial.cpp");
#endif
#include "conio.h"
#include "Tserial.cpp"
#include <time.h>
#include "cv.h"
#include"highgui.h"
#define _USE_MATH_DEFINES
#include <math.h>
//#include <delay.h>

IplImage* img0;
IplImage*  img;
int corb(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=1,cnti=1,sumj=1,cntj=1,ci,cj;
    uchar *data;
    data = (uchar *)img0->imageData;
    height=img0->height;
    width=img0->width;
    step=img0->widthStep;
    channels=img0->nChannels;
    
    for(i=0;i<height;i++)
    {
                       
                         for(j=0;j<width;j++)
                         {
                                             if(data[i*step+j*channels+0]<50&&data[i*step+j*channels+1]<50&&data[i*step+j*channels+2]<50)
                                             {
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
    ci= (sumi/(cnti));
    cj=(sumj/(cntj));    
    if (f==1)
    return ci;
    else if(f==0)
    return cj;                                                                                    
    
}
int corr(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=1,cnti=1,sumj=1,cntj=1,ci,cj;
    uchar *data;
    data = (uchar *)img0->imageData;
    height=img0->height;
    width=img0->width;
    step=img0->widthStep;
    channels=img0->nChannels;
    
    for(i=0;i<height;i++)
    {
                       
                         for(j=0;j<width;j++)
                         {
                                             if(data[i*step+j*channels+0]<50&&data[i*step+j*channels+1]<50&&data[i*step+j*channels+2]<50)
                                             {
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
    ci= (sumi/(cnti));
    cj=(sumj/(cntj));    
    if (f==1)
    return ci;
    else if(f==0)
    return cj;                                                                                    
    
}
int corp(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=1,cnti=1,sumj=1,cntj=1,ci,cj;
    uchar *data;
    data = (uchar *)img0->imageData;
    height=img0->height;
    width=img0->width;
    step=img0->widthStep;
    channels=img0->nChannels;
    
    for(i=0;i<height;i++)
    {
                       
                         for(j=0;j<width;j++)
                         {
                                             if(data[i*step+j*channels+0]<50&&data[i*step+j*channels+1]<50&&data[i*step+j*channels+2]<50)
                                             {
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
    ci= (sumi/(cnti));
    cj=(sumj/(cntj));    
    if (f==1)
    return ci;
    else if(f==0)
    return cj;                                                                                    
    
}
int cory(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=1,cnti=1,sumj=1,cntj=1,ci,cj;
    uchar *data;
    data = (uchar *)img0->imageData;
    height=img0->height;
    width=img0->width;
    step=img0->widthStep;
    channels=img0->nChannels;
    
    for(i=0;i<height;i++)
    {
                       
                         for(j=0;j<width;j++)
                         {
                                             if(data[i*step+j*channels+0]<50&&data[i*step+j*channels+1]<50&&data[i*step+j*channels+2]<50)
                                             {
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
    ci= (sumi/(cnti));
    cj=(sumj/(cntj));    
    if (f==1)
    return ci;
    else if(f==0)
    return cj;                                                                                    
    
}


/*void mouseHandler(int event, int x, int y, int flags, void *param)
{   
    
    int height,width,step,channel;
    uchar* data=(uchar*)img0->imageData;
    height=img0->height;
    width=img0->width;
    channel=img0->nChannels;
    step=img0->widthStep;
    switch(event) {
        // left button down 
        case CV_EVENT_LBUTTONDOWN:
            fprintf(stdout, "Left button down (%d, %d).\n", x, y);
            fprintf(stdout, "b=%d   g =%d , r=%d\n",data[y*step+x*channel+0],data[y*step+x*channel+1],data[y*step+x*channel+2]);            
            break;
       
        // right button down 
        case CV_EVENT_RBUTTONDOWN:
            fprintf(stdout, "Right button down (%d, %d).\n", x, y);
            break;
       
        // mouse move 
        case CV_EVENT_MOUSEMOVE:
             fprintf(stdout, "Left button down (%d, %d).\n", x, y);
            fprintf(stdout, "b=%d   g =%d , r=%d\n",data[y*step+x*channel+0],data[y*step+x*channel+1],data[y*step+x*channel+2]);            
            break;
            // draw a rectangle 
           // img1 = cvCloneImage(img0);
          /*  cvRectangle(img1,
                        cvPoint(x - 15, y - 15),
                        cvPoint(x + 15, y + 15),
                        cvScalar(0, 0, 255, 0), 2, 8, 0);
            //cvShowImage("image", img1);
            //break;
    }
}*/

int main(){
    Tserial *com;
    char ch;
    com = new Tserial();
    com->connect("COM3", 4800, spNONE);
    CvCapture *capture = 0;
    IplImage  *frame = 0;
    int       key = 0;
    com->sendChar('a');
    int rpx,rpy,ryx,ryy,bx,by,rpx1,rpy1,ryx1,ryy1,bx1,by1;
    double theta1=0.1,theta2=0.1;
    /* initialize camera */
    capture = cvCaptureFromCAM(0);
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 1024 );

    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 720 );

    /* always check */
    if ( !capture ) {
        fprintf( stderr, "Cannot open initialize webcam!\n" );
        return 1;
    }
 
    /* create a window for the video */
    cvNamedWindow( "image", CV_WINDOW_AUTOSIZE );
 
    while( key != 'q' ) {
        /* get a frame */
        img = cvQueryFrame( capture );
      
        /* always check */
        if( !img ) break;
        
        img0=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        cvCvtColor(img,img0,CV_BGR2HSV);
        // cvSetMouseCallback( "image", mouseHandler, img0 );
      // cvThreshold(img0, img0, 85, 255, CV_THRESH_BINARY);
       
        /* display curent frame */
        cvShowImage( "image", img0 );
        rpx=corp(img0,1);
        ryx=cory(img0,1);
        bx=corr(img0,1);
        rpy=corp(img0,0);
        ryy=cory(img0,0);
        by=corr(img0,0);
        rpx1=rpx-ryx;
        rpy1=rpx-ryy;
        bx1=bx-ryx;
        by1=by-ryy;
        theta1=atan((double)rpy1/(double)rpx1);
        theta2=atan((double)by1/(double)bx1);
        if(theta1>0 && theta1-theta2>0 && rpx1>0)
        com->sendChar('r');
        else if(theta1<=0 && M_PI+theta1-theta2>0)
        com->sendChar('l');
        else if(theta1<0 && theta2>=0 && rpx<ryx)
        com->sendChar('r');
        else if(theta1>0 && theta1-theta2<0)
        com->sendChar('l');
        else if(theta1>0 && theta1-theta2>0 && rpx1<0)
        com->sendChar('l');
        else if(theta1-theta2==0.0 && rpx1*bx1>0)
        com->sendChar('f');
        else if(theta1-theta2==0.0 && rpx1*bx1<0){
        com->sendChar('r');
        cvWaitKey(5);
        }
        /* exit if user press 'q' */
        key = cvWaitKey( 1 );
        cvReleaseImage(&img0);
        
            }


    /* free memory */
    cvDestroyWindow( "image" );
    cvReleaseCapture( &capture );
    com->disconnect();
    return 0;
}
