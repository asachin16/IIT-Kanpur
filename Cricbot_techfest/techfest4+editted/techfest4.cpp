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

int cmaxx=95,cmaxy=70;
IplImage* img0;
IplImage*  img;
int corr(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    data = (uchar *)img0->imageData;
    height=img0->height;
    width=img0->width;
    step=img0->widthStep;
    channels=img0->nChannels;
    int h,s,v;
    
    for(i=0;i<height;i++)
    {
                       
                         for(j=0;j<width;j++)
                         {
                                             if (i<cmaxy && j<cmaxx)
                                             break;
                                             
                                             h=data[i*step+j*channels+0];
                                             s=data[i*step+j*channels+1];
                                             v=data[i*step+j*channels+2];
    
                                             //if(h>=160/*&&h<=180 */&& s>=185 &&  s<=205&&v>=170 && v<=190)
                                             //if((h>170||h<10)&&(s>125&&s<185)&&(v>115&&v<220))
                                             if((/*h>170||*/h<25)&&(s>200&&s<255)&&(v>100&&v<200))
                                             //if((h>60&&h<90)&&(s>100&&s<160)&&(v>30&&v<50))
                                             {
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
    if(cnti<25)
    return 0; 
    if(cnti>1&&cntj>1){
                       cnti--;
                       cntj--;
                       }
                       
    ci= (sumi/(cnti));
    cj=(sumj/(cntj));    
    if (f==0)
    return ci;
    else if(f==1)
    return cj;                                                                                    
    
}
int corp(IplImage* img0,int f){
    long long int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    data = (uchar *)img0->imageData;
    height=img0->height;
    width=img0->width;
    step=img0->widthStep;
    channels=img0->nChannels;
    int h,s,v;
    
    
    for(i=0;i<height;i++)
    {
                       
                         for(j=0;j<width;j++)
                         {
                                             h=data[i*step+j*channels+0];
                                             s=data[i*step+j*channels+1];
                                             v=data[i*step+j*channels+2];
    
                                             //if(h>=145 && h<=165 && s>=135 &  s<=155&& v>=235 && v<=255)
                                             //if((h>140&&h<175)&&(s>140&&s<170)&&(v>215&&v<255))
                                             //if((h>140&&h<160)&&(s>140&&s<170)&&(v>200&&v<255))
                                             //if((h>150&&h<180)&&(s>140&&s<170)&&(v>200&&v<255))
                                             if((h>150&&h<180)&&(s>140&&s<180)&&(v>190&&v<220))
                                             
                                             {
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
    if(cnti>1&&cntj>1){
                       cnti--;
                       cntj--;
                       }
    ci= (sumi/(cnti));
    cj=(sumj/(cntj));
    //printf("%lld\n",ci);    
    if (f==0)
    return ci;
    else if(f==1)
    return cj;                                                                                    
    
}
int cory(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    data = (uchar *)img0->imageData;
    height=img0->height;
    width=img0->width;
    step=img0->widthStep;
    channels=img0->nChannels;
    int h,s,v;
    
    for(i=0;i<height;i++)
    {
                       
                         for(j=0;j<width;j++)
                         {
                                             h=data[i*step+j*channels+0];
                                             s=data[i*step+j*channels+1];
                                             v=data[i*step+j*channels+2];
    
                                             //if(h>=32 && h<=52 && s>=110 &&  s<=130&& v>=230 && v<=250)
                                             //if((h>30&&h<50)&&(s>110&&s<145)&&(v>200&&v<245))
                                             if((h>30&&h<50)&&(s>110&&s<155)&&(v>165&&v<240))
                                             {
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
    if(cnti>1&&cntj>1){
                       cnti--;
                       cntj--;
                       }
    ci= (sumi/(cnti));
    cj=(sumj/(cntj));    
    if (f==0)
    return ci;
    else if(f==1)
    return cj;                                                                                    
    
}


void mouseHandler(int event, int x, int y, int flags, void *param)
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
                        cvScalar(0, 0, 255, 0), 2, 8, 0);*/
            //cvShowImage("image", img1);
            //break;
    }
}

int main(){
    Tserial *com;
    char ch;
    com = new Tserial();
    com->connect("COM3", 4800, spNONE);
    CvCapture *capture = 0;
    IplImage  *frame = 0;
    int       key = 0;
    com->sendChar('a');
    int rpx,rpy,ryx,ryy,bx,by,rpx1,rpy1,ryx1,ryy1,bx1,by1,ccx1,ccy1;
    int ccx=91,ccy=45;
    double theta1,theta2;
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
         cvSetMouseCallback( "image", mouseHandler, img0 );
      // cvThreshold(img0, img0, 85, 255, CV_THRESH_BINARY);
      cvDilate(img0,img0,NULL,1);
     // cvErode(img0,img0,NULL,1);
       
        /* display curent frame */
        cvShowImage( "image", img );
        rpx=corp(img0,1);
        ryx=cory(img0,1);
        bx=corr(img0,1);
        
        rpy=corp(img0,0);
        ryy=cory(img0,0);
        by=corr(img0,0);
        printf("px=%d\tyx=%d\trx=%d\t py=%d\t yy=%d\t ry=%d \n",rpx,ryx,bx,rpy,ryy,by);
        rpx1=rpx-ryx;
        rpy1=rpy-ryy;
        bx1=bx-ryx;
        by1=by-ryy;
        ccx1=ccx-ryx;
        ccy1=ccy-ryy;
        
      //printf("%lf\t %lf\t %lf\t%lf\n", theta1, theta2,theta2-theta1,M_PI+theta2-theta1);
      if(bx!= 0 ){
              com->sendChar('o');
              theta1=atan((double)rpy1/(double)rpx1);
              theta2=atan((double)by1/(double)bx1);
              if(theta1-theta2<0.4 && theta1-theta2>-0.4 && rpx1*bx1>0){
                             com->sendChar('f');
                             }
              else if(theta1-theta2<0.1 && theta1-theta2>-0.1 && rpx1*bx1<0)
                             {
                             com->sendChar('l');
                             }
              else if(rpx1>0 && bx1>0 && theta2-theta1<0)
                             com->sendChar('l');
             
             else if(rpx1>0 && bx1>0 && theta2-theta1>0)
                            com->sendChar('r');
             
             else if(rpx1 < 0 && bx1 < 0 && theta2-theta1 < 0)
                            com->sendChar('l');
             
             else if(rpx1 < 0 && bx1 < 0 && theta2-theta1 > 0)
                            com->sendChar('r');
             
             else if(rpx1>0 && bx1<0 &&M_PI+ theta2-theta1>0 && M_PI+theta2-theta1<M_PI){
                            com->sendChar('R');
             //cvWaitKey(1);
             }
             else if(rpx1>0 && bx1<0 && M_PI+ theta2-theta1>M_PI){
                            com->sendChar('L');
             //cvWaitKey(1);
             }
             else if(rpx1<0 && bx1>0 &&M_PI+ theta1-theta2>0.1 && M_PI+ theta1-theta2 <M_PI){
                            com->sendChar('L');
             //cvWaitKey(1);
             }
             else if(rpx1<0 && bx1>0 && M_PI+ theta1-theta2<M_PI){
                            com->sendChar('R');
             //cvWaitKey(1);
             }
        }
        else if (bx==0&&sqrt(double((ccx-rpx)*(ccx-rpx))+double((ccy-rpy)*(ccy-rpy)))>=35.0){  
             //printf("%lf", sqrt(double((ccx-rpx)*(ccx-rpx))+double((ccy-rpy)*(ccy-rpy))));
             theta1=atan((double)rpy1/(double)rpx1);
             theta2=atan((double)ccy1/(double)ccx1);
             com->sendChar('c');
             if(theta1-theta2<0.4 && theta1-theta2>-0.4 && rpx1*ccx1>0){
                             com->sendChar('f');
             }
             else if(theta1-theta2<0.1 && theta1-theta2>-0.1 && rpx1*ccx1<0)
             {
                             com->sendChar('l');
             }
      else if(rpx1>0 && ccx1>0 && theta2-theta1<0)
             com->sendChar('l');
             
      else if(rpx1>0 && ccx1>0 && theta2-theta1>0)
             com->sendChar('r');
             
      else if(rpx1 < 0 && ccx1 < 0 && theta2-theta1 < 0)
             com->sendChar('l');
             
      else if(rpx1 < 0 && ccx1 < 0 && theta2-theta1 > 0)
             com->sendChar('r');
             
        else if(rpx1>0 && ccx1<0 &&M_PI+ theta2-theta1>0 && M_PI+theta2-theta1<M_PI){
             com->sendChar('R');
             //cvWaitKey(1);
             }
        else if(rpx1>0 && ccx1<0 && M_PI+ theta2-theta1>M_PI){
             com->sendChar('L');
             //cvWaitKey(1);
             }
       else if(rpx1<0 && ccx1>0 &&M_PI+ theta1-theta2>0.1 && M_PI+ theta1-theta2 <M_PI){
             com->sendChar('L');
             //cvWaitKey(1);
             }
        else if(rpx1<0 && ccx1>0 && M_PI+ theta1-theta2<M_PI){
             com->sendChar('R');
             //cvWaitKey(1);
             }
             
        }
                  
        else if(sqrt(double((ccx-rpx)*(ccx-rpx))+double((ccy-rpy)*(ccy-rpy)))<40.0){
        com->sendChar('s');
        com->sendChar('o');
        }
             
        
             
                                                  
        /* exit if user press 'q' */
        key = cvWaitKey(1);
        cvReleaseImage(&img0);
        //com->sendChar('d');
        
            }


    /* free memory */
    cvDestroyWindow( "image" );
    cvReleaseCapture( &capture );
    com->disconnect();
    return 0;
}
