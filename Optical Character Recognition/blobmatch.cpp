#if (defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) || (defined(__APPLE__) & defined(__MACH__)))
#include <cv.h>
#include <highgui.h>
#else
#include <opencv/cv.h>
#include <opencv/highgui.h>
#endif

#include <cvblob.h>
#include "cvblob.cpp"
#include "cvlabel.cpp"
//#include "cvaux.cpp"
//#include "cvcolor.cpp"
//#include "cvcontour.cpp"
//#include "cvtrack.cpp"
using namespace cvb;
float percentagematch(IplImage *num,IplImage *temp)
{
      int hm,wm,sm,cm,pixcnt=0,totalpix=0,ct,st,i,j;
    uchar *datam;
    uchar *datat;
    datam=(uchar *)num->imageData;
    datat=(uchar *)temp->imageData;
    hm=num->height;
    wm=num->width;
    sm=num->widthStep;
    cm=num->nChannels;
    st=temp->widthStep;
    ct=temp->nChannels;
    //printf("%d  %d  %d  %d\n",cm,ct,sm,st);
    cvSaveImage("test.jpg",num);
    for(i=0;i<hm;i++)
    {
                     for(j=0;j<wm;j++)
                     {
                                      
                                      totalpix++;
                                      if((int)datat[i*st+j*ct+0] != (int)datam[i*sm+j*cm+0])//&&datat[i*sm+j*cm+0]==0)
                                      pixcnt=pixcnt+1;
                                      if((int)datat[i*st+j*ct+0] == (int)datam[i*sm+j*cm+0])
                                      pixcnt=pixcnt-1;
                                      }
                                      }
                                   // printf("%d  %d\n",datat[20*st+20*ct+0],datam[20*sm+20*cm+0]);
                                    // printf("pixel count with two = %d  ,  %d\n",pixcnt,totalpix);
                                     //printf("percentage= %f",(pixcnt/(float)totalpix)*100);
                                      return ((pixcnt/(float)totalpix)*100);
                                      
                                      }
int main()
{
    IplImage* img;
    IplImage* grey;
    IplImage* labelImg;
    IplImage* imgOut;
   /* IplImage* onetemp;
    IplImage* twotemp;
    IplImage* fourtemp;
    IplImage* threetemp;*/
    IplImage* numtemp[10];
    IplImage* chartemp[27];
   IplImage* char1temp[27];
    double xcor[50],ycor[50];
    int b=0;
    char result[50];
    
    //IplImage* chartemp[4];
    
    //float diff=600;
    numtemp[1]=cvLoadImage("1_template.png",0);
    numtemp[2]=cvLoadImage("2_template.png",0);
    numtemp[3]=cvLoadImage("3_template.png",0);
    numtemp[4]=cvLoadImage("4_template.png",0);
    numtemp[5]=cvLoadImage("5_template.png",0);
    numtemp[6]=cvLoadImage("6_template.png",0);
    numtemp[7]=cvLoadImage("7_template.png",0);
    numtemp[8]=cvLoadImage("8_template.png",0);
    numtemp[9]=cvLoadImage("9_template.png",0);
    chartemp[1]=cvLoadImage("A_template.png",0);
    chartemp[2]=cvLoadImage("B_template.png",0);
    chartemp[3]=cvLoadImage("C_template.png",0);
    chartemp[4]=cvLoadImage("D_template.png",0);
    chartemp[5]=cvLoadImage("E_template.png",0);
    chartemp[6]=cvLoadImage("F_template.png",0);
    chartemp[7]=cvLoadImage("G_template.png",0);
    chartemp[8]=cvLoadImage("H_template.png",0);
    chartemp[9]=cvLoadImage("I_template.png",0);
    chartemp[10]=cvLoadImage("J_template.png",0);
    chartemp[11]=cvLoadImage("K_template.png",0);
    chartemp[12]=cvLoadImage("L_template.png",0);
    chartemp[13]=cvLoadImage("M_template.png",0);
    chartemp[14]=cvLoadImage("N_template.png",0);
    chartemp[15]=cvLoadImage("O_template.png",0);
    chartemp[16]=cvLoadImage("P_template.png",0);
    chartemp[17]=cvLoadImage("Q_template.png",0);
    chartemp[18]=cvLoadImage("R_template.png",0);
    chartemp[19]=cvLoadImage("S_template.png",0);
    chartemp[20]=cvLoadImage("T_template.png",0);
    chartemp[21]=cvLoadImage("U_template.png",0);
    chartemp[22]=cvLoadImage("V_template.png",0);
    chartemp[23]=cvLoadImage("W_template.png",0);
    chartemp[24]=cvLoadImage("X_template.png",0);
    chartemp[25]=cvLoadImage("Y_template.png",0);
    chartemp[26]=cvLoadImage("Z_template.png",0);
    char1temp[1]=cvLoadImage("a1_template.png",0);
    char1temp[2]=cvLoadImage("b1_template.png",0);
    char1temp[3]=cvLoadImage("c1_template.png",0);
    char1temp[4]=cvLoadImage("d1_template.png",0);
    char1temp[5]=cvLoadImage("e1_template.png",0);
    char1temp[6]=cvLoadImage("f1_template.png",0);
    char1temp[7]=cvLoadImage("g1_template.png",0);
    char1temp[8]=cvLoadImage("h1_template.png",0);
    char1temp[9]=cvLoadImage("i1_template.png",0);
    char1temp[10]=cvLoadImage("j1_template.png",0);
    char1temp[11]=cvLoadImage("k1_template.png",0);
    char1temp[12]=cvLoadImage("l1_template.png",0);
    char1temp[13]=cvLoadImage("m1_template.png",0);
    char1temp[14]=cvLoadImage("n1_template.png",0);
    char1temp[15]=cvLoadImage("o1_template.png",0);
    char1temp[16]=cvLoadImage("p1_template.png",0);
    char1temp[17]=cvLoadImage("q1_template.png",0);
    char1temp[18]=cvLoadImage("r1_template.png",0);
    char1temp[19]=cvLoadImage("s1_template.png",0);
    char1temp[20]=cvLoadImage("t1_template.png",0);
    char1temp[21]=cvLoadImage("u1_template.png",0);
    char1temp[22]=cvLoadImage("v1_template.png",0);
    char1temp[23]=cvLoadImage("w1_template.png",0);
    char1temp[24]=cvLoadImage("x1_template.png",0);
    char1temp[25]=cvLoadImage("y1_template.png",0);
    char1temp[26]=cvLoadImage("z1_template.png",0);
    
     
    
        
    
    IplImage* num[10];
    IplImage* ch[27];
    IplImage* ch1[27];
    
    
    
    // IplImage* charnum[4];
    
    float per[62];
    float maxper=0.000;
    int numb;
    int i;
    for(i=1;i<10;i++){
    num[i]=cvCreateImage(cvGetSize(numtemp[i]),IPL_DEPTH_8U,1);
    }
    for(i=1;i<27;i++){
    ch[i]=cvCreateImage(cvGetSize(chartemp[i]),IPL_DEPTH_8U,1);
    }
  for(i=1;i<27;i++){
    ch1[i]=cvCreateImage(cvGetSize(char1temp[i]),IPL_DEPTH_8U,1);
    }
    
    int minx,maxx,miny,maxy;
    CvSeq *contours=0;
    int key=0,height,width,step,channels,j;
    uchar *data;
    
    CvCapture* capture;
    capture=cvCaptureFromCAM(0);
    while(key!='q')
    {
    cvGrabFrame(capture);
    img=cvRetrieveFrame(capture);
    cvShowImage("vid",img);
    key=cvWaitKey(5);
    if(key=='s'){
    cvSaveImage("cap.jpg",img);
    break;
}
}
    cvDestroyWindow("vid");
    img=cvLoadImage("cap.jpg",1);
    //printf("work\n");
    grey=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    //imgOut=cvCloneImage(img);
    imgOut=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    labelImg=cvCreateImage(cvGetSize(img),IPL_DEPTH_LABEL,1);
    cvCvtColor(img, grey, CV_BGR2GRAY);
    //printf("work\n");
    
    cvThreshold(grey, grey, 80, 255, CV_THRESH_BINARY);
    cvShowImage("thresh",grey);
    cvWaitKey(0);
    height=grey->height;
    width=grey->width;
    step=grey->widthStep;
    channels=grey->nChannels;
    data=(uchar *)grey->imageData;
    for(i=0;i<height;i++)
    {
                        for(j=0;j<width;j++)
                         {
                                             data[i*step+j*channels+0]=255-data[i*step+j*channels+0];
                                             }
                                             }
                                             
   // cvMinAreaRect2(grey,NULL);
  // printf("work");
    CvBlobs blobs;
    cvLabel(grey, labelImg, blobs);
    cvRenderBlobs(labelImg, blobs, img, imgOut);
    cvFilterByArea(blobs,100,10000);
    cvShowImage("blobs",imgOut);
    IplImage* grey1;
    grey1=grey;
   // for(CvBlobs::const_iterator it=blobs.begin();it!=blobs.end();++it)(
    
    //getchar();
    
    for(CvBlobs::const_iterator it=blobs.begin();it!=blobs.end();++it)
    {                           
                                grey=grey1;
                                //printf("work");
    //printf("  %d  %d  %d  %d %d\n",it->second->minx,it->second->miny,it->second->maxx,it->second->maxy,it->second->area);
//if(diff>pow((pow((it->second->centroid.x)-(height/2),2)+pow((it->second->centroid.y)-(width/2),2)),0.5))
//{
                                                //diff=pow((pow((it->second->centroid.x)-(height/2),2)+pow((it->second->centroid.y)-(width/2),2)),0.5);
                                                minx=it->second->minx;
                                                miny=it->second->miny;
                                                maxx=it->second->maxx;
                                                maxy=it->second->maxy;
                                               // }
//}

//printf("%d \n",maxx);
    cvSaveImage("blobtwo.jpg",grey);
    cvShowImage("thresh",grey);
    cvSetImageROI(grey,cvRect(minx,miny,(maxx-minx),(maxy-miny)));
    //cvShowImage("thresh",grey);
    for(i=1;i<10;i++){
    cvResize(grey,num[i],CV_INTER_LINEAR);
    }
    for(i=1;i<27;i++){
    cvResize(grey,ch[i],CV_INTER_LINEAR);
    }
    for(i=1;i<27;i++){
    cvResize(grey,ch1[i],CV_INTER_LINEAR);
    }
 //   cvShowImage("sized",num);
   // cvShowImage("win",twotemp);
   for(i=1;i<10;i++){
    cvThreshold(num[i], num[i], 20, 255, CV_THRESH_BINARY);
}
    for(i=1;i<27;i++){
    cvThreshold(ch[i], ch[i], 20, 255, CV_THRESH_BINARY);
}
    for(i=1;i<27;i++){
    cvThreshold(ch1[i], ch1[i], 20, 255, CV_THRESH_BINARY);
}
    /*cvThreshold(onenum, onenum, 20, 255, CV_THRESH_BINARY);
    cvThreshold(threenum, threenum, 20, 255, CV_THRESH_BINARY);
    cvThreshold(fournum, fournum, 20, 255, CV_THRESH_BINARY);
    cvThreshold(charnum[0], charnum[0], 20, 255, CV_THRESH_BINARY);
    cvThreshold(charnum[1], charnum[1], 20, 255, CV_THRESH_BINARY);
    cvThreshold(charnum[2], charnum[2], 20, 255, CV_THRESH_BINARY);
    cvThreshold(charnum[3], charnum[3], 20, 255, CV_THRESH_BINARY);*/
//printf("work");


    /**per[1]=percentagematch(twonum,twotemp);
    per[0]=percentagematch(onenum,onetemp);
    per[2]=percentagematch(threenum,threetemp);
    per[3]=percentagematch(fournum,fourtemp);
    per[4]=percentagematch(charnum[0],chartemp[0]);
    per[5]=percentagematch(charnum[1],chartemp[1]);
    per[6]=percentagematch(charnum[2],chartemp[2]);
    per[7]=percentagematch(charnum[3],chartemp[3]);*/
    //printf("work");
    for(i=1;i<10;i++){
                      per[i]=percentagematch(num[i],numtemp[i]);
                      }
    for(i=1;i<27;i++){
                      per[i+9]=percentagematch(ch[i],chartemp[i]);
                      }
    for(i=1;i<27;i++){
                      per[i+35]=percentagematch(ch1[i],char1temp[i]);
                      }
    
    
    
    
    
    for(i=1;i<62;i++)
    {
                    //printf("work");
                    if(maxper<per[i])
                    {
                    maxper=per[i];
                    numb=(i);
                    
                    }
                    }
    
                    //printf("\n\n maxper= %f  number is %d\n\n ",maxper,numb);
                    if(maxper >50.0 && numb<10){
                    result[b]=numb+'0';
                    xcor[b]=(it->second->centroid.x);
                    ycor[b]=(it->second->centroid.y);
                    b++;
                    }
                    else if(maxper>50.0&& numb>9&&numb<36){
                    result[b]=((numb-10)+'A');
                    xcor[b]=(it->second->centroid.x);
                    ycor[b]=(it->second->centroid.y);
                    b++;
                    }
                    else if(maxper>50.0&& numb>35&&numb<62){
                    result[b]=((numb-36)+'a');
                    xcor[b]=(it->second->centroid.x);
                    ycor[b]=(it->second->centroid.y);
                    b++;
                    }
                    
                    
                    maxper=0.000;
                    
    
}

for(i=0;i<b;i++)
{
                for(j=i+1;j<b;j++)
                {
                                  if(xcor[i]>xcor[j] && abs(ycor[i]-ycor[j])<20)
                                  {
                                                     swap(xcor[i],xcor[j]);
                                                     swap(result[i],result[j]); 
                                                     swap(ycor[i],ycor[j]);                  
                                  }                  
                }                
}
i=0;
while(i<b){
                 if(abs(ycor[i]-ycor[i+1])<20&&(i+1)<b){
                 printf("%c",result[i]);
                 i++;
                 }
                 else{
                      printf("%c",result[i]);
                      printf("\n");
                      i++;
                      }
                 
                 
                 }
                 

    
    /*int hm,wm,sm,cm,pixcnt=0,totalpix=0,ct,st;
    uchar *datam;
    uchar *datat;
    datam=(uchar *)num->imageData;
    datat=(uchar *)twotemp->imageData;
    hm=num->height;
    wm=num->width;
    sm=num->widthStep;
    cm=num->nChannels;
    st=twotemp->widthStep;
    ct=twotemp->nChannels;
    printf("%d  %d  %d  %d\n",cm,ct,sm,st);
    cvSaveImage("test.jpg",num);
    for(i=0;i<hm;i++)
    {
                     for(j=0;j<wm;j++)
                     {
                                      
                                      totalpix++;
                                      if((int)datat[i*st+j*ct+0] != (int)datam[i*sm+j*cm+0])//&&datat[i*sm+j*cm+0]==0)
                                      pixcnt=pixcnt+1;
                                      if((int)datat[i*st+j*ct+0] == (int)datam[i*sm+j*cm+0])
                                      pixcnt=pixcnt-1;
                                      }
                                      }
                                      printf("%d  %d\n",datat[20*st+20*ct+0],datam[20*sm+20*cm+0]);
                                      printf("pixel count with two = %d  ,  %d\n",pixcnt,totalpix);
                                      printf("percentage= %f",(pixcnt/(float)totalpix)*100);
    */
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvReleaseImage(&imgOut);
    cvReleaseImage(&grey);
    for(i=1;i<10;i++){
                     cvReleaseImage(&num[i]);
                     cvReleaseImage(&numtemp[i]);
                     }
    for(i=1;i<27;i++){
                     cvReleaseImage(&ch[i]);
                     cvReleaseImage(&chartemp[i]);
                     }
    for(i=1;i<27;i++){
                     cvReleaseImage(&ch1[i]);
                     cvReleaseImage(&char1temp[i]);
                     }
   /* cvReleaseImage(&twonum);
    cvReleaseImage(&onenum);
    cvReleaseImage(&threenum);
    cvReleaseImage(&fournum);
    cvReleaseImage(&twotemp);
    cvReleaseImage(&onetemp);
    cvReleaseImage(&threetemp);
    cvReleaseImage(&fourtemp);*/
    cvReleaseImage(&labelImg);
    cvReleaseCapture(&capture);
    cvReleaseBlobs(blobs);
    
}

    

