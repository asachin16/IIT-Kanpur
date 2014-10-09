#include <cv.h>
#include <highgui.h>
#include <cvblob.h>
#include "cvblob.cpp"
#include "cvlabel.cpp"
using namespace cvb;

 IplImage* img;
 IplImage* grey;
 IplImage* imgOut;
 FILE *fp;

void Centroid()
{
     int area,x,y;
      IplImage* labelImg;
      imgOut=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
      labelImg=cvCreateImage(cvGetSize(img),IPL_DEPTH_LABEL,1);
      CvBlobs blobs;
      cvLabel(grey, labelImg, blobs);
      cvFilterByArea(blobs,200,400);
      cvRenderBlobs(labelImg, blobs, img, imgOut,CV_BLOB_RENDER_COLOR);
      cvShowImage("blobs",imgOut);
      cvShowImage("Binary_image",grey);
      cvSaveImage("img1.jpg",imgOut);
      cvWaitKey(0);  
       for(CvBlobs::const_iterator it=blobs.begin();it!=blobs.end();++it)
    {
         area=it->second->area;
         x=it->second->centroid.x;
         y=it->second->centroid.y;
         printf("x=%d\ty=%d\tarea=%d\n",x,y,area); 
         fprintf(fp,"x=%d\ty=%d\n",x,y);                       
    }    
}

int main()
{
    int i;
    fp=fopen("DSC_0023.txt","w");
    int height,width,step,channels,j;
    img=cvLoadImage("DSC_0028.JPG",1);
    cvShowImage("img",img);
    grey=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
   
    cvCvtColor(img, grey, CV_BGR2GRAY);
     cvSaveImage("grey.jpg",grey);
    cvThreshold(grey, grey,50, 255, CV_THRESH_BINARY_INV);
    cvSaveImage("binary.jpg",grey);
    cvShowImage("img1",grey);
    Centroid();
    cvWaitKey(0);  
}
