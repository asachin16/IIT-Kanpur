#include "cv.h"
#include "highgui.h"
#include "math.h"
int main()
{
    IplImage* input;  //Initialise input image pointer
    IplImage* output;//initialise output image pointer
    
    input=cvLoadImage("1.jpg",1);//load input image [0=gray;1=colored]                Note: this image file must be in same folder where you store this C++/C program file
    
    cvNamedWindow("ii",1);//create a named window with title ii  ;
    cvShowImage("ii",input);//show image saved in input pointer in the window named ii
    
    output=cvCloneImage(input);
   
    cvThreshold(input, output, 150, 255, CV_THRESH_BINARY);// pre Cloning is necessary and input image cannot be altered (reason not known)
    //cvThreshold(input, output, threshold, maxValue, thresholdType);
    /* thresholdTypes:-
       CV_THRESH_BINARY - max value if more than threshold, else 0
       CV_THRESH_BINARY_INV - 0 if more than threshold , else max value
       CV_THRESH_TRUNC - threshhold if more than threshold , else no change
       CV_THRESH_TOZERO - no change if more than threshold else 0
       CV_THRESH_TOZERO_INV - 0 if morethan threshold , else no change
       
       Note:  CV_THRESH_OTSU  returns an optimum threshold value of image by otsu algorithm which can be used in above function
       */
    //Note that image is stored as 1D array of GBRGBRGB.....   and the functions work on all elements(all pixels' every channel)
    
    cvNamedWindow("oo",1);
    cvShowImage("oo",output);
    
    cvWaitKey(0); //this function waits indefinately till key press if 0 or negative number is given to it(and also returns key's ascii value) . for positive numbers , it waits for corresponding milliseconds
    
    cvDestroyWindow( "oo" ); //destroy the window
    cvDestroyWindow("ii");
    cvSaveImage("output.jpg",output);
    cvReleaseImage( &output ); //release the memory for the image
    cvReleaseImage( &input ); //release the memory for the image
    return 0;
}
