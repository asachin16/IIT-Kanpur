#include "cv.h"
#include "highgui.h"
#include "math.h"
int main()
{
    int i;
    int j;
    IplImage* input;
    input=cvLoadImage("1.jpg",1);
    cvNamedWindow("ii",1);
    cvShowImage("ii",input);
    
    /*
    An image is a structure with elements :-
    
    nChannels (integer)= no. of channels in 1 pixel
    
    width (integer)= no. of pixels on X axis
    
    height (integer) = no. of pixels on Y xis
    
    widthstep (integer) = number of bytes between points in the same column and successive rows        
                                                                     Note :"  widthstep = nChannels * width " is npt always true , there can be some gaps between the end of ith row and the start of (i+1)th row
    
    depth (integer) = no. of bits storing one character /element
    
    imageData (uchar pointer) = pointer to the first row of image data(image data is stored as a 1D stack)
    
    
    
    there ate a lot many other elements which will come eventually
   */ 
    printf("nChannels=%d width=%d  height=%d widthstep=%d  depth=%d  align=%d",input->nChannels,input->width,input->height,input->widthStep,input->depth,input->align);
    
    
    cvWaitKey(0);
    cvReleaseImage( &input );
    return 0;
}
    
