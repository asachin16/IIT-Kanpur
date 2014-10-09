#include "cv.h"
#include "highgui.h"
#include<stdio.h>
int height,width;
IplImage* image;



void my_mouse_callback( int event, int x, int y, int flags, void* param )
{
   uchar *pimage   =  (uchar*)image->imageData;
printf("\nx=%d\t y=%d\n r=%d \tg=%d \tb=%d\n",x,y,pimage[y*image->widthStep + x*image->nChannels+2],pimage[y*image->widthStep + x*image->nChannels+1],pimage[y*image->widthStep + x*image->nChannels+0]);
} 


int main()
{
      
    
    image=cvLoadImage("img1.jpg",1);
     cvCvtColor(image,image,CV_BGR2HSV);
    height=image->height;
    width=image->width;
    
    cvNamedWindow("image",1);
    cvSetMouseCallback("image", my_mouse_callback, NULL);
    cvShowImage("image",image);
    
    cvWaitKey(0); 
    
    cvDestroyWindow( "image" );
    cvReleaseImage( &image );  
    return 0;
}
