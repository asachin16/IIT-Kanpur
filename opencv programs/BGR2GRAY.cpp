#include "cv.h"
#include "highgui.h"
int main()
{
    IplImage* input;  
    IplImage* output;
    input=cvLoadImage("apple.jpg",1);
    output=cvCreateImage(cvGetSize(input),IPL_DEPTH_8U,1);
    cvCvtColor(input,output,CV_BGR2GRAY);
    
    cvNamedWindow("win",1);
    cvShowImage("win",output);
    cvWaitKey(0);
    cvSaveImage("output.jpg",output);
    cvReleaseImage( &output );
    cvReleaseImage( &input );
    return 0;
}
