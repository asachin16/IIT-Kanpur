#include "cv.h"
#include "highgui.h"

int main()
{
    int i;
    int j;
    IplImage* input;  
    IplImage* output;
    input=cvLoadImage("10.jpg",1);
    cvNamedWindow("ii",1);
    cvShowImage("ii",input);
    printf("nChannels=%d width=%d  height=%d widthstep=%d  depth=%d  align=%d",input->nChannels,input->width,input->height,input->widthStep,input->depth,input->align);
   
   
   output=cvCreateImage(cvSize(input->width, input->height ),input->depth, input->nChannels );
    
    uchar *pinput   =  (uchar*)input->imageData;//saving data pointer of input image as pinput  
    uchar *poutput   = ( uchar* )output->imageData;//savind data pointer of output image as poutput
    
    
    
    for(i=0;i<input->height;i++)
            for(j=0;j<input->width;j++)
            {
                      
                      poutput[i*input->widthStep + j*input->nChannels + 2]=pinput[i*input->widthStep + j*input->nChannels + 2];//copying red elements of input to output
                     poutput[i*input->widthStep + j*input->nChannels + 0]=0;//initialising blue elements of output image as 0
                      poutput[i*input->widthStep + j*input->nChannels + 1]=0;//initialising red elements of output image as 0;
                      
                      //Note : initialisng B and G as 0 may be excluded but recommended as it may take garbage value , test it yourself
            }
    
    
    
    
    cvNamedWindow("aa",1);
    cvShowImage("aa",output);
    cvWaitKey(0);
    cvDestroyWindow("ii");
    cvDestroyWindow( "aa" ); 
    cvReleaseImage( &output );
    cvReleaseImage( &input );
    return 0;
}
    
