#include"highgui.h"
#include"cv.h"

int main()
{
    int c;//to store ascii value of key pressed
    CvCapture *capture=cvCreateCameraCapture(1);//initiate camera 
    //because of recursively updating frame , here we dont need to wait for camera as for some ms frame will be black and then as camera starts , frame will update and shaw image
    IplImage *frame;
    if(capture!=NULL)
    {
                     frame=cvQueryFrame(capture);//take current image in camera and give it to frame pointer
                     cvNamedWindow("img");
                     while(1)
                     {
                             
                             cvShowImage("img",frame);
                            frame=cvQueryFrame(capture);
                            c=cvWaitKey(1);//frame rate time period (if not given system will hang as system processing speed is very fast
                            if(c>0&&c<255)
                                     {
                                            cvDestroyWindow( "img" );
                                            cvReleaseImage( &frame ); 
                                            cvReleaseCapture(&capture);
                                            return 0;
                                     }
                     }
    }
}
