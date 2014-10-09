#include "cv.h"
#include"highgui.h"
    IplImage* img;

void mouseHandler(int event, int x, int y, int flags, void *param)
{   
    
    int height,width,step,channel;
    uchar* data=(uchar*)img->imageData;
    height=img->height;
    width=img->width;
    channel=img->nChannels;
    step=img->widthStep;
    switch(event) {
        case CV_EVENT_MOUSEMOVE:
             fprintf(stdout, "Left button down (%d, %d).\n", x, y);
            fprintf(stdout, "b=%d   g =%d , r=%d\n",data[y*step+x*channel+0],data[y*step+x*channel+1],data[y*step+x*channel+2]);            
            break;
            
    }
}


int main(){

    CvCapture *capture = 0;
    IplImage  *frame = 0;
    int       key = 0;
    capture = cvCaptureFromCAM(0);
    
    if ( !capture ) {
        fprintf( stderr, "Cannot open initialize webcam!\n" );
        return 1;
    }
    cvNamedWindow( "image", CV_WINDOW_AUTOSIZE );
 
    while( key != 'q' ) {
        /* get a frame */
        img = cvQueryFrame( capture );
      
        /* always check */
        if( !img ) break;
        
        cvErode(img,img,NULL,1);
         cvDilate(img,img,NULL,1);
         cvErode(img,img,NULL,1);
         cvDilate(img,img,NULL,1);
         cvErode(img,img,NULL,1);
         cvDilate(img,img,NULL,1);
         cvSetMouseCallback( "image", mouseHandler, img );
         cvShowImage( "image", img );
         key = cvWaitKey(1);
        }
        cvDestroyWindow( "image" );
    cvReleaseCapture( &capture );
}
