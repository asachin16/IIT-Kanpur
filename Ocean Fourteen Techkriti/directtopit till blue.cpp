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
#define PI 3.14159265

//int boundarymax= ,boundarymax= ;
IplImage* img0;
IplImage*  img;
IplImage*  imgpink;
IplImage*  imgyellow;
IplImage*  imgblack;
IplImage*  imgwhite;
IplImage*  imggreen;
IplImage*  imgblue;
IplImage*  imgviolet;

int gix,giy,gfy,bix,biy;


int violet(IplImage* img0,int f){
    long long int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    uchar *datav;
    data = (uchar *)img0->imageData;
    datav = (uchar *)imgviolet->imageData;
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
                                              if((h>150&&h<185)&&(s>125&&s<150)&&(v>240&&v<=255))  //Pink Caliberation
                                             {
                                                                                                                                      datav[i*step+j*channels+0]=255;
                                                                                                                                      datav[i*step+j*channels+1]=255;
                                                                                                                                      datav[i*step+j*channels+2]=255;
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                             else
                                             {
                                                                                                                                      datav[i*step+j*channels+0]=0;
                                                                                                                                      datav[i*step+j*channels+1]=0;
                                                                                                                                      datav[i*step+j*channels+2]=0;
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
  
int pink(IplImage* img0,int f){
    long long int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    uchar *datap;
    data = (uchar *)img0->imageData;
    datap = (uchar *)imgpink->imageData;
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
                                              if((h>150&&h<185)&&(s>125&&s<150)&&(v>240&&v<=255))  //Pink Caliberation
                                             {
                                                                                                                                      datap[i*step+j*channels+0]=255;
                                                                                                                                      datap[i*step+j*channels+1]=255;
                                                                                                                                      datap[i*step+j*channels+2]=255;
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                             else
                                             {
                                                                                                                                      datap[i*step+j*channels+0]=0;
                                                                                                                                      datap[i*step+j*channels+1]=0;
                                                                                                                                      datap[i*step+j*channels+2]=0;
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
int yellow(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    uchar *datay;
    data = (uchar *)img0->imageData;
    datay = (uchar *)imgyellow->imageData;
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
                                             
                                             if (j>150){
                                                        }
    
                                             else if((h>25&&h<45)&&(s>30&&s<80)&&(v>240&&v<=255))   //Yellow caliberation
                                             {
                                                                                                                                      datay[i*step+j*channels+0]=255;
                                                                                                                                      datay[i*step+j*channels+1]=255;
                                                                                                                                      datay[i*step+j*channels+2]=255;
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                             else
                                             {
                                                                                                                                      datay[i*step+j*channels+0]=0;
                                                                                                                                      datay[i*step+j*channels+1]=0;
                                                                                                                                      datay[i*step+j*channels+2]=0;
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


int green(IplImage* img0,int f){
    int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    uchar *datag;
    data = (uchar *)img0->imageData;
    datag = (uchar *)imggreen->imageData;
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
                                             if((h>25&&h<45)&&(s>30&&s<80)&&(v>240&&v<=255))   //Green caliberation
                                             {
                                                                                                                                      datag[i*step+j*channels+0]=255;
                                                                                                                                      datag[i*step+j*channels+1]=255;
                                                                                                                                      datag[i*step+j*channels+2]=255;
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                             else
                                             {
                                                                                                                                      datag[i*step+j*channels+0]=0;
                                                                                                                                      datag[i*step+j*channels+1]=0;
                                                                                                                                      datag[i*step+j*channels+2]=0;
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
int blue(IplImage* img0,int f){
    long long int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    uchar *datab;
    data = (uchar *)img0->imageData;
    datab = (uchar *)imgblue->imageData;
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
                                              if((h>150&&h<185)&&(s>125&&s<150)&&(v>240&&v<=255))  //Pink Caliberation
                                             {
                                                                                                                                      datab[i*step+j*channels+0]=255;
                                                                                                                                      datab[i*step+j*channels+1]=255;
                                                                                                                                      datab[i*step+j*channels+2]=255;
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                             else
                                             {
                                                                                                                                      datab[i*step+j*channels+0]=0;
                                                                                                                                      datab[i*step+j*channels+1]=0;
                                                                                                                                      datab[i*step+j*channels+2]=0;
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



int black(IplImage* img,int f){
    long long int height,width,step,channels,i,j,sumi=0,cnti=1,sumj=0,cntj=1,ci,cj;
    uchar *data;
    uchar *databl;
    data = (uchar *)img->imageData;
    databl = (uchar *)imgblack->imageData;
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
                                              if((h<10)&&(s<10)&&(v<=10))  //black Caliberation
                                             {
                                                                                                                                      databl[i*step+j*channels+0]=0;
                                                                                                                                      databl[i*step+j*channels+1]=0;
                                                                                                                                      databl[i*step+j*channels+2]=0;
                                                                                                                                      sumi=sumi+i;
                                                                                                                                      cnti=cnti+1;
                                                                                                                                      sumj=sumj+j;
                                                                                                                                      cntj=cntj+1;
                                                                                                                                      }
                                             else
                                             {
                                                                                                                                      databl[i*step+j*channels+0]=255;
                                                                                                                                      databl[i*step+j*channels+1]=255;
                                                                                                                                      databl[i*step+j*channels+2]=255;
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



int main()
{
    Tserial *com;
    char ch;
    com = new Tserial();
    com->connect("COM3", 4800, spNONE);
    CvCapture *capture = 0;
    IplImage  *frame = 0;
    int key = 0;
   // com->sendChar('a');
    int pinkx,pinky,yellowx,yellowy,bluey,greeny,violetx,violety,botx,boty,i=0;
    int hb,sb,cb,wb;
    int greenx[21]={1},bluex[21]={1};
    double bottheta,theta2,slope;
    int flag=1,flag1=1;
    /* initialize camera */
    capture = cvCaptureFromCAM(0);
    //cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 1024 );

    //cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 720 );

    /* always check */
    if ( !capture )
    {     
        fprintf( stderr, "Cannot open initialize webcam!\n" );
        return 1;
    }
 
    /* create a window for the video */
    cvNamedWindow( "image", CV_WINDOW_AUTOSIZE );
 
    while( key != 'q' ) 
    {
        /* get a frame */
        img = cvQueryFrame( capture );
      
        /* always check */
        if( !img ) break;
        
        img0=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        imgblue=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        imgpink=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        imgyellow=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        imggreen=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        imgblack=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        imgviolet=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        cvCvtColor(img,img0,CV_BGR2HSV);
        cvSetMouseCallback( "image", mouseHandler, img0 );
      // cvThreshold(img0, img0, 85, 255, CV_THRESH_BINARY);
         cvErode(img0,img0,NULL,1);
         cvDilate(img0,img0,NULL,1);
       
        /* display curent frame */
        cvShowImage( "image", img );
        pinkx=pink(img0,1);
        yellowx=yellow(img0,1);
        for(i=20;i>0;i--)
                          {
                               bluex[i]=bluex[i-1];
                           
                           }
        bluex[0]=blue(img0,1);
        for(i=20;i>0;i--)
                          {
                               greenx[i]=greenx[i-1];
                           
                           }
        greenx[0]=green(img0,1);
        violetx=violet(img0,1);
        black(img,1);
        uchar* datablack=(uchar*)imgblack->imageData;
         hb=img0->height;
          wb=img0->width;
          cb=img0->nChannels;
          sb=img0->widthStep;
          uchar* datablue=(uchar*)imgblue->imageData;
          uchar* datayellow=(uchar*)imgyellow->imageData;
        pinky=pink(img0,0);
        yellowy=yellow(img0,0);
        bluey=blue(img0,0);
        greeny=green(img0,0);
        violety=violet(img0,0);
        
        cvShowImage( "imageblue", imgblue ); 
        cvShowImage( "imagepink", imgpink );
        cvShowImage( "imageyellow", imgyellow );
        cvShowImage( "imagegreen", imggreen );
        cvShowImage( "imageblack", imgblack );
        cvShowImage( "imageviolet", imgviolet );
        
        
        botx=pinkx-violetx;
        boty=pinky-violety;
        bottheta=atan((double)boty/(double)botx)*180/PI;
         if(pinky>giy && pinky<gfy){
                   if(greenx[0]-greenx[20]>0 && greenx[0]>gix){
                                           com->sendChar('F');
                                           } 
                   else{
                                           com->sendChar('s');
                                           }
        }
        
        else if(bottheta<45 && bottheta >-45 && pinkx>violetx && flag==1){//right
                       flag1=1;
                       if(datablack[pinky*sb+(pinkx+15)*cb+0]!=0)
                       {
                                   if(bottheta >10)
                                   {
                                               com->sendChar('L');
                                               printf("R\n");
                                   }
                                   else if (bottheta <-10)
                                   {
                                        com->sendChar('R');
                                         printf("L\n");
                                   }
                                   else if(bottheta >5)
                                   {
                                               com->sendChar('d');
                                                printf("l\n");
                                   }
                                   else if (bottheta <-5)
                                   {
                                        com->sendChar('e');
                                         printf("e\n");
                                   }
                                   
                                   else
                                   {
                                       com->sendChar('F');
                                        printf("F\n");
                                   }
                       }
                                   
                       else if(datablack[pinky*sb+(pinkx+15)*cb+0]==0)
                       {
                                                                
                                  if(datablack[(pinky-30)*sb+(pinkx)*cb+0]!=0)
                                  {
                                        com->sendChar('L');
                                         printf("L\n");
                                        flag=0;
                                  }
                                  else if(datablack[(pinky+30)*sb+(pinkx)*cb+0]!=0)
                                  {
                                        com->sendChar('R');
                                         printf("R\n");
                                        flag=0;
                                  }
                                  
                       }
                                   
               }
               
               
               else if(bottheta>45 && 180+bottheta <135 && pinky>violety && flag1==1){//back                 
                                   flag=1;
                          if(datablack[(pinky+15)*sb+(pinkx)*cb+0]!=0)
                          {
                                   if(bottheta <80)
                                   {
                                               com->sendChar('R');
                                                printf("R\n");
                                   }
                                   else if (180+bottheta >100)
                                   {
                                        com->sendChar('L');
                                         printf("L\n");
                                   }
                                   else if(bottheta <85)
                                   {
                                               com->sendChar('e');
                                                printf("r\n");
                                   }
                                   else if (180+bottheta >95)
                                   {
                                        com->sendChar('d');
                                         printf("l\n");
                                   }
                                   
                                   else
                                   {
                                       com->sendChar('F');
                                        printf("F\n");
                                   }
                       }
                                   
                       else if(datablack[(pinky+15)*sb+(pinkx)*cb+0]==0)
                       {
                                                                
                                  if(datablack[(pinky)*sb+(pinkx-30)*cb+0]!=0)
                                  {
                                        com->sendChar('R');
                                         printf("R\n");
                                        flag1=0;
                                  }
                                  else if(datablack[(pinky)*sb+(pinkx+30)*cb+0]!=0)
                                  {
                                        com->sendChar('L');
                                         printf("L\n");
                                        flag1=0;
                                  }
                                  
                       }
                                   
                    
                    }
              else if(180+bottheta>135 && 180+bottheta < 225 && pinkx<violetx && flag==1){//left
                       flag1=1;
                       if(datablack[pinky*sb+(pinkx-15)*cb+0]!=0)
                       {
                                   if(180+bottheta <170)
                                   {
                                               com->sendChar('R');
                                               printf("R\n");
                                   }
                                   else if (180+bottheta >190)
                                   {
                                        com->sendChar('L');
                                        printf("L\n");
                                   }
                                   else if(180+bottheta <175)
                                   {
                                               com->sendChar('e');
                                               printf("r\n");
                                   }
                                   else if (180+bottheta>195)
                                   {
                                        com->sendChar('d');
                                        printf("l\n");
                                   
                                   }
                                   
                                   else
                                   {
                                       com->sendChar('F');
                                       printf("F\n");
                                   }
                       }
                                   
                       else if(datablack[pinky*sb+(pinkx-15)*cb+0]==0)
                       {
                                                                
                                  if(datablack[(pinky-30)*sb+(pinkx)*cb+0]!=0)
                                  {
                                        com->sendChar('R');
                                        printf("R\n");
                                        flag=0;
                                  }
                                  else if(datablack[(pinky+30)*sb+(pinkx)*cb+0]!=0)
                                  {
                                        com->sendChar('L');
                                        printf("L\n");
                                        flag=0;
                                  }
                                  
                       }
                                   
               }
        
              
               else if(180+bottheta > 225 && bottheta < -45  && pinky < violety &&flag1==1){//straight                              
                                   flag=1;
                          if(datablack[(pinky-15)*sb+(pinkx)*cb+0]!=0)
                          {
                                      if(180+bottheta <260)
                                   {
                                               com->sendChar('R');
                                               printf("R\n");
                                   }
                                   else if (bottheta >-80)
                                   {
                                        com->sendChar('L');
                                        printf("L\n");
                                   }
                                   else if(180+bottheta <265)
                                   {
                                               com->sendChar('e');
                                               printf("r\n");
                                   }
                                   else if (bottheta >-85)
                                   {
                                        com->sendChar('d');
                                        printf("l\n");
                                   }
                                   
                                   else if( !(pinkx > bix && pinky < biy))
                                   {
                                       com->sendChar('F');
                                       printf("F\n");
                                   }
                                   else{
                                        if(((datablue[(pinky-30)*sb+(pinkx-15)*cb+0]!=0)&&(bluex[20]-bluex[0]<0)) || datayellow[(pinky-30)*sb+pinkx*cb+0]!=0)
                                        {
                                                                                 com->sendChar('F');
                                                                                 printf("F\n");
                                                                                 
                                        }
                                        else{
                                                                                 com->sendChar('s');
                                                                                 printf("s\n");
                                             }
                                        
                                        }
                       }
                                   
                       else if(datablack[(pinky-25)*sb+(pinkx)*cb+0]==0)
                       {
                                                                
                                  
                                  if(datablack[(pinky)*sb+(pinkx-30)*cb+0]!=0)
                                  {
                                        com->sendChar('L');
                                        printf("L\n");
                                        flag1=0;
                                  }
                                  else if(datablack[(pinky)*sb+(pinkx+30)*cb+0]!=0)
                                  {
                                        com->sendChar('R');
                                        printf("R\n");
                                        flag1=0;
                                  }
                                  
                       }
                                   
                    
                    }
        
        
        
        
        
        
        key = cvWaitKey(1);
        cvReleaseImage(&img0);
        cvReleaseImage(&imgblue);
        cvReleaseImage(&imgpink);
        cvReleaseImage(&imgyellow);
        cvReleaseImage(&imggreen);
        cvReleaseImage(&imgblack);
        cvReleaseImage(&imgviolet);
        
     }


    /* free memory */
    cvDestroyWindow( "image" );
    cvDestroyWindow( "imageblue");
    cvDestroyWindow( "imagepink");
    cvDestroyWindow( "imageyellow");
    cvDestroyWindow( "imageblack");
    cvDestroyWindow( "imagegreen");
    cvDestroyWindow( "imageviolet");
    cvReleaseCapture( &capture );
    com->disconnect();
    return 0;
}
