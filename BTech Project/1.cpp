#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cvblob.h>
#include "cvblob.cpp"
#include "cvlabel.cpp"
using namespace cvb;

 IplImage* img;
 IplImage* grey;
 IplImage* imgOut;
 float cfactor;
 FILE *fp;
 FILE *fb;
 char *c="easvacd";
 


void mouseHandler(int event, int x, int y, int flags, void *param)
{   
    switch(event) {
        case CV_EVENT_LBUTTONDOWN:
             fprintf(stdout, "Left button down (%d, %d).\n", x, y);            
            break;
            
    }
}

float fraction(IplImage* image){
      uchar *data;
      int cnt=0,cnt1=0,i,j,height,width,step,channels;
      height=image->height;
      width=image->width;
      step=image->widthStep;
      channels=image->nChannels;
      data=(uchar *)image->imageData;
      for(i=0;i<height;i++)
    {
                        for(j=0;j<width;j++)
                         {
                                            if(data[i*step+j*channels+0]==0 && data[i*step+j*channels+1]==0 && data[i*step+j*channels+2]==0)
                                            {
                                              cnt1++; 
                                            }
                                            else
                                            cnt++;
                         }
    }
    return (float)cnt/(cnt+cnt1);
      
      
}



void Grain_size()
{
     int area,x,y;
      IplImage* labelImg;
      imgOut=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
      labelImg=cvCreateImage(cvGetSize(img),IPL_DEPTH_LABEL,1);
      CvBlobs blobs;
      cvLabel(grey, labelImg, blobs);
      cvFilterByArea(blobs,20,10000000);
      cvRenderBlobs(labelImg, blobs, img, imgOut,CV_BLOB_RENDER_COLOR);
      cvShowImage("blobs",imgOut);
      cvSaveImage("D2-4-1000x_c.png",imgOut);
      cvShowImage("Binary_image",grey);
      cvSaveImage("D2-4-1000x_d.png",grey);
      cvWaitKey(0);  
       for(CvBlobs::const_iterator it=blobs.begin();it!=blobs.end();++it)
    {
         area=it->second->area;
         //printf("%d\n",area); 
         //printf("cfactor1=%f\n",cfactor);
        // printf("%f\n",area*cfactor*cfactor); 
         // printf("%lf\n",it->second->centroid.x);
		 fprintf(fb,"%f\n",area*cfactor*cfactor);                        
    }    
}

void correction_factor(){
     int lengthp,lengthm;
     IplImage* img1;
     img1=cvLoadImage("D2-4-5000x.jpg",1);
     cvNamedWindow("image",1);
     cvSetMouseCallback( "image", mouseHandler, img1 );
     cvShowImage( "image", img1 );
     cvWaitKey(0);
     printf("Enter size in Pixcels\n");
     scanf("%d",&lengthp);
     printf("Enter size in Microns\n");
     scanf("%d",&lengthm);
     cfactor = (float)lengthm/lengthp;
     printf("cfactor=%f\n",cfactor);
     cvDestroyWindow( "image" );
     cvReleaseImage( &img1 );      
}
void final_binary(){
     int height,width,step,channels,j,i;
     uchar *data;
     height=imgOut->height;
    width=imgOut->width;
    step=imgOut->widthStep;
    channels=imgOut->nChannels;
    data=(uchar *)imgOut->imageData;
    for(i=0;i<height;i++)
    {
                        for(j=0;j<width;j++)
                         {
                                            if(data[i*step+j*channels+0]==0 && data[i*step+j*channels+1]==0 && data[i*step+j*channels+2]==0)
                                            {
                                            }
                                            else
                                            {
                                                                                                          data[i*step+j*channels+0]=255;
                                                                                                          data[i*step+j*channels+1]=255;
                                                                                                          data[i*step+j*channels+2]=255;
                                            }
                         }
    }
}
void agglomuration(int division){
     IplImage* img2;
    long int i,j,k,l,height,width,step,channels,x,y,cnt1=0,cnt=0,cnt2=0,cnt3=0,flag=0,flag1=0;
     float b,area;
     
     uchar *data2,*data1;
     height=imgOut->height;
     width=imgOut->width;
     step=imgOut->widthStep;
     channels=imgOut->nChannels;
     data2=(uchar *)imgOut->imageData;
     x=width/division;
     y=height/division;
     img2=cvCloneImage(imgOut);
     data1=(uchar *)img2->imageData;
     area=x*y*cfactor*cfactor;
     
     for(k=0;k<=height-y;k=k+y)
    {
                        for(l=0;l<=width-x;l=l+x)
                         {
                                              flag=1;
                                              
                                              for(i=k;i<k+y;i++)
                                              {                 flag1=1;
                                                                   for(j=l;j<l+x;j++)
                                                                   {
                                                                                     if(data2[i*step+j*channels+0]==0 && data2[i*step+j*channels+1]==0 && data2[i*step+j*channels+2]==0)
                                                                                     {
                                                                                                                     cnt1++;
                                                                                                                     
                                                                                     }
                                                                                     else
                                                                                     {
                                                                                                                     cnt++;
                                                                                                                    
                                                                                     }
                                                                                     if(flag==1)
                                                                                     {
                                                                                                                    data1[i*step+j*channels+0]=0;
                                                                                                                    data1[i*step+j*channels+1]=0;
                                                                                                                    data1[i*step+j*channels+2]=255;
                                                                                     }
                                                                                     if(flag1==1)
                                                                                     {
                                                                                                                    data1[i*step+j*channels+0]=0;
                                                                                                                    data1[i*step+j*channels+1]=0;
                                                                                                                    data1[i*step+j*channels+2]=255;
                                                                                                                    flag1=0;
                                                                                     }
                                                                                                 
                                                                                                                                                                         
                                                                                   
                                                                                   
                                                                   }
                                                                   flag=0;
                                              }
                                              b=(float)cnt/(cnt+cnt1);
                                              cnt3++;
                                              if (b>0.8)
                                              {
                                                        cnt2++;
                                              }
                                              cnt=0;
                                              cnt1=0;
                         }
    }
    cvShowImage(c,img2);
    cvWaitKey(1);
    fprintf(fp,"%f\t%f\n",area,(float)cnt2*100/cnt3);  
    c++;
     
}

int main()
{
    int i;
    fp=fopen("fin.txt","w");
    fb=fopen("fib.txt","w");
    
    int height,width,step,channels,j;
   // correction_factor();
    img=imread("D2-4-1000x.png",1);
    cvShowImage("img",img);
    grey=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    cvCvtColor(img, grey, CV_BGR2GRAY);
    cvSaveImage("grey.jpg",grey);
    cvThreshold(grey, grey,60, 255, CV_THRESH_BINARY_INV);
    cvShowImage("grey",grey);
    cvSaveImage("binary.jpg",grey);
    //Grain_size();
    //final_binary();
    cvWaitKey(0);
    printf("Volume Fraction=%f\n",fraction(imgOut));
    //cvShowImage("imgout",imgOut);
    //cvSaveImage("D2-4-1000x_b.png",imgOut);
    cvWaitKey(0);
   // for(i=50;i<250;i++)
    //agglomuration(i);
    

    cvWaitKey(0);
    
    
    
    
}
