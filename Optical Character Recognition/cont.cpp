#include<iostream>
#include<cv.h>
#include<highgui.h>
int main()
{
         IplImage* img;
         CvSeq* contour=NULL;
         CvMemStorage* storage=cvCreateMemStorage(0);
         img=cvLoadImage("two.png",0);
         cvShowImage("img",img);
         cvWaitKey(0);
         cvFindContours(img,storage,&contour,sizeof(CvContour),CV_RETR_CCOMP ,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
         cvDrawContours(img,contour,CV_RGB(200,0,0),CV_RGB(0,255,0),1,3,8);
         cvShowImage("cont",img);
         cvWaitKey(0);
         cvReleaseImage(&img);
         }
         
