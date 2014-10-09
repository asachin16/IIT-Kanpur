#include "cv.h"
#include "highgui.h"
#include "math.h"
int main()
{
    IplImage* input;  
    IplImage* output;
    input=cvLoadImage("1.jpg",1);
    
    output=cvCreateImage(cvGetSize(input),IPL_DEPTH_8U,3);
    cvCvtColor(input,output,CV_BGR2HSV);//Note:  output image must be created
    //This function takes an image(input pointer)in one color space and saves image (in output pointer) in other color space
    //eg: RGB<->HSV (CV_BGR2HSV, CV_RGB2HSV, CV_HSV2BGR, CV_HSV2RGB) ,      RGB<->HLS (CV_BGR2HLS, CV_RGB2HLS, CV_HLS2BGR, CV_HLS2RGB)
    //RGB<->CIE XYZ.Rec 709 with D65 white point (CV_BGR2XYZ, CV_RGB2XYZ, CV_XYZ2BGR, CV_XYZ2RGB),       RGB<->YCrCb JPEG (a.k.a. YCC) (CV_BGR2YCrCb, CV_RGB2YCrCb, CV_YCrCb2BGR, CV_YCrCb2RGB)
    //RGB<->CIE L*a*b* (CV_BGR2Lab, CV_RGB2Lab, CV_Lab2BGR, CV_Lab2RGB),                           RGB<->CIE L*u*v* (CV_BGR2Luv, CV_RGB2Luv, CV_Luv2BGR, CV_Luv2RGB)
    //Bayer->RGB (CV_BayerBG2BGR, CV_BayerGB2BGR, CV_BayerRG2BGR, CV_BayerGR2BGR, CV_BayerBG2RGB, CV_BayerGB2RGB, CV_BayerRG2RGB, CV_BayerGR2RGB) {Reverse conversion is not possible in bayer}
    
    
    
    
    
    
    
    cvShowImage("ii",input);
    cvNamedWindow("aa",1);
    cvShowImage("aa",output);
    cvWaitKey(0);
    cvDestroyWindow( "aa" ); 
    cvReleaseImage( &output );
    cvReleaseImage( &input );
    return 0;
}
    
