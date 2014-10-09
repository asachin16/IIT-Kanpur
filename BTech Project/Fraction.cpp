#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cvblob.h>
#include "cvblob.cpp"
#include "cvlabel.cpp"
using namespace cvb;

IplImage* image;
IplImage* grey;
IplImage* image1;
IplImage* grey1;
IplImage* imgOut;
IplImage* imgOut1;
FILE *fp;
void mouseHandler(int event, int x, int y, int flags, void *param)
{   
    switch(event) {
        case CV_EVENT_LBUTTONDOWN:
             fprintf(stdout, "Left button down (%d, %d).\n", x, y);            
            break;
            
    }
}
void Grain_size()
{
     int area,area1;
     int i=0;
      IplImage* labelImg;
      imgOut=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
      labelImg=cvCreateImage(cvGetSize(image),IPL_DEPTH_LABEL,1);
      CvBlobs blobs;
      cvLabel(grey, labelImg, blobs);
      cvFilterByArea(blobs,15,100000);
      cvRenderBlobs(labelImg, blobs, image, imgOut,CV_BLOB_RENDER_COLOR);
      cvShowImage("blobs",imgOut);
      cvShowImage("Binary_image",grey);
      IplImage* labelImg1;
      imgOut1=cvCreateImage(cvGetSize(image1),IPL_DEPTH_8U,3);
      labelImg1=cvCreateImage(cvGetSize(image1),IPL_DEPTH_LABEL,1);
      CvBlobs blob;
      cvLabel(grey1, labelImg1, blob);
      cvFilterByArea(blob,15,100000);
      cvRenderBlobs(labelImg1, blob, image1, imgOut1,CV_BLOB_RENDER_COLOR);
      cvShowImage("blob1",imgOut1);
      cvShowImage("Binary_image1",grey1);
      CvBlobs::const_iterator it1=blob.begin();
      cvWaitKey(0);  
       for(CvBlobs::const_iterator it=blobs.begin();it!=blobs.end()&& it1!=blob.end();++it,++it1)
    {
         area=it->second->area;
         area1=it1->second->area;
        //printf("%f\n",(float)area1/area*100);
        // printf("%d \t %d \n",x[i],y[i]);
        //fprintf(fp,"%d\n",area1); 
		 fprintf(fp,"%f\n",(float)area1/area*100);   
//		 i++;                     
    }    
}
int main(){
	fp=fopen("fraction.txt","w");
	int height,width,step,channels,j;
	image=cvLoadImage("123.jpg",1);
	cvShowImage("image",image);
    grey=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,1);
    cvCvtColor(image, grey, CV_BGR2GRAY);
    cvThreshold(grey, grey,200, 255, CV_THRESH_BINARY);
    cvShowImage("binary",grey);
    image1=cvLoadImage("D2-4-5000x_b.png",1);
    cvShowImage("image",image);
    grey1=cvCreateImage(cvGetSize(image1),IPL_DEPTH_8U,1);
    cvCvtColor(image1, grey1, CV_BGR2GRAY);
    cvThreshold(grey1, grey1,200, 255, CV_THRESH_BINARY);
    cvShowImage("binary",grey1);
    Grain_size();
    cvWaitKey(0);
    fclose(fp);
}
