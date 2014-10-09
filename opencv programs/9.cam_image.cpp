#include"highgui.h"
#include"cv.h"

int main()
{
    CvCapture *capture=cvCreateCameraCapture(0);//initiate camera 
    for(int i=0;i<100000000&& capture!=NULL ;i++);//starting camera takes some time and we can take any frame only after camera starts or frame value will be  black
    
    IplImage *frame;
    
    
    if(capture!=NULL)//camera has begun starting itself
    {
                     frame=cvQueryFrame(capture);//take current image in camera and give it to frame pointer
                     cvNamedWindow("img");
                     cvShowImage("img",frame);
                     cvWaitKey(0);
                     cvDestroyWindow( "img" );
                     cvReleaseImage( &frame ); 
                     cvReleaseCapture(&capture);
                     return 0;
    }


}
