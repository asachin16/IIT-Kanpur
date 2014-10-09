#include "cv.h"
#include "highgui.h"

IplImage* temp;


void my_mouse_callback( int event, int x, int y, int flags, void* param )
{
   uchar *ptemp  =  (uchar*)temp->imageData;
printf("\nx=%d(%d)\t y=%d(%d)\t\th=%d \ts=%d \tv=%d\n",x,temp->width,y,temp->height,ptemp[y*temp->widthStep + x*temp->nChannels+0],ptemp[y*temp->widthStep + x*temp->nChannels+1],ptemp[y*temp->widthStep + x*temp->nChannels+2]);
} 


int main()
{
   int i,j,h,s,v;
   int x_max=0,x_min=0,y_min=0,y_max=0;
   int start_x=95,start_y=110,end_x=640,end_y=340;//Place region of interest here
   IplImage* input;
   IplImage* output;
   input=cvLoadImage("10.jpg",1); 
   
    temp=cvCreateImage(cvGetSize(input),IPL_DEPTH_8U,3);
    output=cvCreateImage(cvGetSize(input),IPL_DEPTH_8U,1);
    
    cvCvtColor(input,temp,CV_BGR2HSV);
    uchar *ptemp  =  (uchar*)temp->imageData;
    uchar *poutput  =  (uchar*)output->imageData;
    
     for(i=0;i<input->height;i++)
            for(j=0;j<input->width;j++)
            {
                                       h=ptemp[i*temp->widthStep + j*temp->nChannels+0];
                                       s=ptemp[i*temp->widthStep + j*temp->nChannels+1];
                                       v=ptemp[i*temp->widthStep + j*temp->nChannels+2];
                                       
                                       if(v<50)//Place your condtion here for black
                                       {
                                                             if(i>start_y&&i<end_y&&j>start_x&&j<end_x)
                                                                         poutput[i*output->widthStep + j]=255;
                                                             else
                                                                         poutput[i*output->widthStep + j]=0;
                                       }
                                       else
                                                   poutput[i*output->widthStep + j]=0;
            }
     
     for(i=0;i<input->height;i++)
     {      for(j=0;j<input->width;j++)
            {
                                       if(poutput[i*output->widthStep + j]==255)
                                      {
                                                                      if(y_max<i)
                                                                                 y_max=i;
                                                                      if(y_min>i||y_min==0)
                                                                                 y_min=i;
                                                                      if(x_min>j||x_min==0)
                                                                                 x_min=j;
                                                                      if(x_max<i)
                                                                                 x_max=j;
                                                                                                               
                                      }
                                       
                                                                      
            }
                               
     }
     printf("x_min=%d  x_max=%d  y_min=%d   y_max=%d\ncentre=(%d,%d)",x_min,x_max,y_min,y_max,(x_min+x_max)/2,(y_min+y_max)/2);      
    cvNamedWindow("input",1);
    cvNamedWindow("output",1);
    
    cvShowImage("input",input);
    cvShowImage("output",output);
    
    cvSetMouseCallback("input", my_mouse_callback, NULL);
    
    
    cvWaitKey(0); 
    
    cvDestroyWindow( "output" );
    cvReleaseImage( &output ); 
    cvReleaseImage( &input );  
    cvReleaseImage( &temp );  
    return 0;
}
