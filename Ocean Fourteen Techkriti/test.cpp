#include <cvblob.h>
#include "cvblob.cpp"
#include "cvlabel.cpp"
#include "cv.h"
#include"highgui.h"

IplImage* img0;
IplImage*  img;
IplImage*  imgpink;

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
                                              if((h>165 && h<180) && (s>100 && s<190) && (v>180 && v<255))  //Pink Caliberation
                                            {
                                                                                                                                  imgpink->imageData[i*imgpink->width + j]=255;
                                                                                                                                      
                                                                                                                                      }
                                             else
                                             {
                                                                                                                                      imgpink->imageData[i*imgpink->width + j]=0;
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
                              
    
}

int main(){
    
    CvCapture *capture = 0;
    IplImage  *frame = 0;
    int key = 0;
    IplImage* labelImg;
    
    capture = cvCaptureFromCAM(0);
    
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
        
        labelImg=cvCreateImage(cvGetSize(img),IPL_DEPTH_LABEL,1);
        img0=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        imgpink=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
        cvCvtColor(img,img0,CV_BGR2HSV);
        cvShowImage( "image", img );
        pink(img0,1);
        CvBlobs blobs;           //declaring blobs
        cvLabel(imgpink, labelImg, blobs);//to detect blob in grey image
        cvFilterByArea(blobs,20,10000);
        cvShowImage( "imagepink", imgpink );
        key = cvWaitKey(1);
        cvReleaseImage(&img0);
        cvReleaseImage(&imgpink);
        }
    
    
}
