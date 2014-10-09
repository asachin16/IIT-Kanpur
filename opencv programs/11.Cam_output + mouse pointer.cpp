#include"highgui.h"
#include"cv.h"
#include<stdio.h>
int height,width;
IplImage* input_frame;
IplImage *output_frame;


void input_mouse_callback( int event, int x, int y, int flags, void* param )
{
   uchar *pimage   =  (uchar*)input_frame->imageData;
printf("\nx=%d(%d)\t y=%d(%d)\t\tr=%d \tg=%d \tb=%d\n",x,width,y,height,pimage[y*input_frame->widthStep + x*input_frame->nChannels+2],pimage[y*input_frame->widthStep + x*input_frame->nChannels+1],pimage[y*input_frame->widthStep + x*input_frame->nChannels+0]);
} 


void output_mouse_callback( int event, int x, int y, int flags, void* param )
{
   uchar *pimage   =  (uchar*)output_frame->imageData;
   printf("\nx=%d(%d)\t y=%d(%d)\t\th=%d \ts=%d \tv=%d\n",x,width,y,height,pimage[y*input_frame->widthStep + x*input_frame->nChannels],pimage[y*input_frame->widthStep + x*input_frame->nChannels+1],pimage[y*input_frame->widthStep + x*input_frame->nChannels+2]);

} 


int main()
{
    int c;//to store ascii value of key pressed
    CvCapture *capture=cvCreateCameraCapture(0);
    if(capture!=NULL)
    {
                     input_frame=cvQueryFrame(capture);//take current image in camera and give it to frame pointer
                     output_frame=cvCreateImage(cvGetSize(input_frame),IPL_DEPTH_8U,3);
                      
                      height=input_frame->height;
                      width=input_frame->width;
                     
                     cvNamedWindow("input");
                     cvNamedWindow("output");
                     
                     cvSetMouseCallback("input", input_mouse_callback, NULL);
                     cvSetMouseCallback("output", output_mouse_callback, NULL);
                     
                     while(1)
                     {
                             cvCvtColor(input_frame,output_frame,CV_BGR2HSV);
                            cvShowImage("input",input_frame);
                            cvShowImage("output",input_frame);
                            input_frame=cvQueryFrame(capture);
                            c=cvWaitKey(2);//frame rate time period (if not given system will hang as system processing speed is very fast
                            if(c>0&&c<255)//Esc key
                            {
                                          cvDestroyWindow( "input" );
                                          cvDestroyWindow("output");
                                          cvReleaseImage( &input_frame ); 
                                          cvReleaseImage( &output_frame ); 
                                          cvReleaseCapture(&capture);
                                          return 0;
                            }
                     }
    }
     
}
