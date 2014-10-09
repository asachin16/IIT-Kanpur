#include "cv.h"
#include "highgui.h"
#include "string.h"
IplImage* temp;


void my_mouse_callback( int event, int x, int y, int flags, void* param )
{
   uchar *ptemp  =  (uchar*)temp->imageData;
printf("\nx=%d(%d)\t y=%d(%d)\t\th=%d \ts=%d \tv=%d\n",x,temp->width,y,temp->height,ptemp[y*temp->widthStep + x*temp->nChannels+0],ptemp[y*temp->widthStep + x*temp->nChannels+1],ptemp[y*temp->widthStep + x*temp->nChannels+2]);
} 


int main()
{
   int i,j,h,s,v;
   IplImage* input;
   IplImage* output;
   IplImage* temp_erode;
   input=cvLoadImage("puzzle.png",1); 
   char c[10];
   
   printf("Enter the color of book needed\n");
   int n=0;
   scanf("%s",c);
   if(!strcmp(c,"red")) n=1;
   else if(!strcmp(c,"yellow")) n=2;
   //printf("%d\n",n);
   IplImage *temp=cvCreateImage(cvGetSize(input),IPL_DEPTH_8U,3);
   output=cvCreateImage(cvGetSize(input),IPL_DEPTH_8U,1);
   cvCvtColor(input,temp,CV_BGR2HSV);
  temp_erode=cvCreateImage(cvGetSize(temp),8,3);
  cvErode(temp,temp_erode,NULL,1);
   uchar *ptemp  =  (uchar*)temp_erode->imageData;
   uchar *poutput  =  (uchar*)output->imageData;
    int e=0;
     for(i=0;i<input->height;i++)
          {  for(j=0;j<input->width;j++)
            {
                                       h=ptemp[i*temp_erode->widthStep + j*temp_erode->nChannels+0];
                                       s=ptemp[i*temp_erode->widthStep + j*temp_erode->nChannels+1];
                                       v=ptemp[i*temp_erode->widthStep + j*temp_erode->nChannels+2];
                               switch (n)
                           { case 1:
                             {if((h>150||h<20)&&v>50&&s>150)//Place your condtion here for red
                                  poutput[i*output->widthStep + j]=255;
                              else
                                 poutput[i*output->widthStep + j]=0;
                                 }
                               break;
                             case 2:
                              {  if(((h<27)&&(h>19))&&((s>135)&&(s<185))&&v>130)
                                     poutput[i*output->widthStep + j]=255;
                                 else poutput[i*output->widthStep +j]=0;
                                   }
                                 break;
                                 default: {printf("Invalid color");
                                        e++;}
                                      break;
                                 }
                                 if(e!=0)
                                 break;                           
                                                                           
            }
               if(e!=0) break;}
  
  
    cvNamedWindow("input",1);
    cvShowImage("input",input);
   if(e==0){
    cvNamedWindow("output",1);
    cvShowImage("output",output);}
  // cvSetMouseCallback("input", my_mouse_callback, NULL);
  // cvSetMouseCallback("output", my_mouse_callback, NULL);
    
    
    cvWaitKey(0); 
    
    cvDestroyWindow( "output" );
    cvDestroyWindow("input");
    cvReleaseImage( &output ); 
    cvReleaseImage( &input );  
    cvReleaseImage( &temp );  
    return 0;
}
