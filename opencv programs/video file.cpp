#include"highgui.h"
#include"cv.h"

int main()
{
    int c;//to store ascii value of key pressed
    CvCapture* capture=cvCreateFileCapture("trial.avi" );
    //because of recursively updating frame , here we dont need to wait for camera as for some ms frame will be black and then as camera starts , frame will update and shaw image
    IplImage *input_frame;
    IplImage* hsv_frame;
    if(capture!=NULL)
    {
                     input_frame=cvQueryFrame(capture);//take current image in camera and give it to frame pointer
                     hsv_frame=cvCreateImage(cvGetSize(input_frame),IPL_DEPTH_8U,3);
                     cvCvtColor(input_frame,hsv_frame,CV_BGR2HSV);
                     cvNamedWindow("input");
                     cvNamedWindow("output");
                     while(1)
                     {
                             cvShowImage("input",input_frame);
                             cvShowImage("output",hsv_frame);
                            input_frame=cvQueryFrame(capture);
                            cvCvtColor(input_frame,hsv_frame,CV_BGR2HSV);
                            c=cvWaitKey(33);//frame rate time period (if not given system will hang as system processing speed is very fast
                            if(c>0&&c<255)
                                     {
                                            cvDestroyWindow( "input" );
                                            cvDestroyWindow( "output" );
                                            cvReleaseImage( &input_frame ); 
                                            cvReleaseImage( &hsv_frame ); 
                                            cvReleaseCapture(&capture);
                                            return 0;
                                     }
                     }
    }
}
