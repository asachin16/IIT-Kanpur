#include "cv.h"
#include "highgui.h"
#include "math.h"
int main()
{
    IplImage* input; 
    IplImage* gray;
    IplImage* output;
    
    input=cvLoadImage("1.jpg",1);
    
    cvNamedWindow("ii",1);
    cvShowImage("ii",input);
    
    gray = cvCreateImage( cvGetSize(input), IPL_DEPTH_8U, 1 );
    cvCvtColor(input,gray,CV_BGR2GRAY);
    
    output=cvCreateImage(cvGetSize(input),input->depth,1);//you may use IPL_DEPTH_8U  instead of input->depth
    cvCanny(gray,output,50,200,3);
    /*   void cvCanny(Single channel image as input, Single-channel image to store the edges found by the function as output, double threshold1, double threshold2, aperture_size)*/
    
    
    //here we need to convert image to gray as canny can only take single channel image as input for canny algorithm
   
   
   
    cvNamedWindow("oo",1);
    cvShowImage("oo",output);
    
    cvWaitKey(0); 
    
    cvDestroyWindow( "oo" ); 
    cvDestroyWindow("ii");
    cvReleaseImage( &output ); 
    cvReleaseImage( &input ); 
    return 0;
}
