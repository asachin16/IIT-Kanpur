#include "cv.h"
#include "highgui.h"
#include "math.h"
int main()
{
    IplImage* input;  //Initialise input image pointer
    IplImage* output;//initialise output image pointer
    
    input=cvLoadImage("apple.jpg",1);//load input image [0=gray;1=colored]                Note: this image file must be in same folder where you store this C++/C program file
    
    cvNamedWindow("ii",1);//create a named window with title ii  ;
    cvShowImage("ii",input);//show image saved in input pointer in the window named ii
    
    output=cvCloneImage(input);//cloning copies image from input to output , including height , width . so no need to "create" image
    
    cvNamedWindow("oo",1);
    cvShowImage("oo",output);
    
    cvWaitKey(0); //this function waits indefinately till key press if 0 or negative number is given to it(and also returns key's ascii value) . for positive numbers , it waits for corresponding milliseconds
    
    cvDestroyWindow( "oo" ); //destroy the window
    cvDestroyWindow("ii");
    cvReleaseImage( &output ); //release the memory for the image
    cvReleaseImage( &input ); //release the memory for the image
    return 0;
}
