/***A BASIC CODE OF PATTERN RECOGNITION
WORK FOR ARIAL FONT WITH BOLD CHARACTERS****/
#include <cv.h>
#include <highgui.h>
#include <cvblob.h>
#include "cvblob.cpp"
#include "cvlabel.cpp"
using namespace cvb;
float percentagematch(IplImage *num,IplImage *temp)//function to find out the %age of num image matching wid template image(temp) 
{                                                             // templates are those images wid which we compare our images(from cam)
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
    //printf("%d  %d  %d  %d\n",cm,ct,sm,st);//in order to find out height, witdh,etc
    cvSaveImage("test.jpg",num);
    for(i=0;i<hm;i++)
    {
                     for(j=0;j<wm;j++)
                     {
                                      
                                      totalpix++;
                                      if((int)datat[i*st+j*ct+0] != (int)datam[i*sm+j*cm+0])//as the num image is inverted image
                                      pixcnt=pixcnt+1;//so pixelcnt should increase 
                                      if((int)datat[i*st+j*ct+0] == (int)datam[i*sm+j*cm+0])
                                      pixcnt=pixcnt-1;
                                      }
                                      }
                                    // printf("pixel count with two = %d  ,  %d\n",pixcnt,totalpix);//to print no. of pixel matching & total pixels
                                     //printf("percentage= %f",(pixcnt/(float)totalpix)*100);
                                      return ((pixcnt/(float)totalpix)*100);//returning %age match
                                      
                                      }
int main()
{
    IplImage* img;
    IplImage* grey;
    IplImage* labelImg;
    IplImage* imgOut;
    IplImage* numtemp[10];//declaring image array in which we give number templates
    IplImage* chartemp[27];//declaring image array in which we give capital letter templates
   IplImage* char1temp[27];//declaring image array in which we give small letter templates
    
    
    numtemp[1]=cvLoadImage("1_template.png",0);//loading num template etc etc
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
    
    
    //blob is a connected region in the image
    
    float per[62];//percentage
    float maxper=0.000;
    int numb;
    int i;
    for(i=1;i<10;i++){
    num[i]=cvCreateImage(cvGetSize(numtemp[i]),IPL_DEPTH_8U,1);//creating image in order to make blob of the same size of template
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
    
    CvCapture* capture;//capturing image from webcam
    capture=cvCaptureFromCAM(0);
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 1024 );

    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 720 );
    while(key!='q')
    {
                   cvGrabFrame(capture);
                   img=cvRetrieveFrame(capture);
                   cvShowImage("vid",img);
                   key=cvWaitKey(5);
                   if(key=='s'){//as soon as 's' is pressed image will be  saved by name cap.jpg
                   cvSaveImage("cap.jpg",img);
                   break;
                   }
    }
    cvDestroyWindow("vid");
    img=cvLoadImage("a.jpg",1);
    grey=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    imgOut=cvCloneImage(img);
    imgOut=cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    labelImg=cvCreateImage(cvGetSize(img),IPL_DEPTH_LABEL,1);
    cvCvtColor(img, grey, CV_BGR2GRAY);//converting image from BGR to GRAY
    
    //cvThreshold(grey, grey, 80, 255, CV_THRESH_BINARY);//threshold image in order to reduce noise
    cvShowImage("thresh",grey);
    cvWaitKey(0);
    height=grey->height;//ascessing image height of grey
    width=grey->width;
    step=grey->widthStep;
    channels=grey->nChannels;
    data=(uchar *)grey->imageData;//saving color data of image in data[] matrix
    for(i=0;i<height;i++)
    {
                        for(j=0;j<width;j++)
                         {
                                             data[i*step+j*channels+0]=255-data[i*step+j*channels+0];//as the blob take black as background so 
                                                                                                          //we are inverting the image which 
                                                                                                          //comes so that the character passed should be white
                                             }
                                             }
                                             
   
    CvBlobs blobs;           //declaring blobs
    cvLabel(grey, labelImg, blobs);//to detect blob in grey image
    cvRenderBlobs(labelImg, blobs, img, imgOut);//to mark blobs in image
    cvFilterByArea(blobs,100,10000);
    cvShowImage("blobs",imgOut);
    IplImage* grey1;
    grey1=grey;
    double xcor[50],ycor[50];//declaring x & y coordinate in order to save x & y co-ordinate of centroid of blob
    int b=0;
    char result[50];
    for(CvBlobs::const_iterator it=blobs.begin();it!=blobs.end();++it)//analysing each blob in successive loop
    {                           
                                                grey=grey1;
                                                minx=it->second->minx;
                                                miny=it->second->miny;
                                                maxx=it->second->maxx;
                                                maxy=it->second->maxy;
                                               


    cvSaveImage("blobtwo.jpg",grey);
    cvSetImageROI(grey,cvRect(minx,miny,(maxx-minx),(maxy-miny)));//setting our region of interest to the blob only in grey image
    for(i=1;i<10;i++){
    cvResize(grey,num[i],CV_INTER_LINEAR);
    }
    for(i=1;i<27;i++){
    cvResize(grey,ch[i],CV_INTER_LINEAR);                                   //resizing blob to the size of each template
    }
    for(i=1;i<27;i++){
    cvResize(grey,ch1[i],CV_INTER_LINEAR);
    }
    for(i=1;i<10;i++){
    cvThreshold(num[i], num[i], 20, 255, CV_THRESH_BINARY);
    }
    for(i=1;i<27;i++){
    cvThreshold(ch[i], ch[i], 20, 255, CV_THRESH_BINARY); //threshholding img in order to reduce noise
    }
    for(i=1;i<27;i++){
    cvThreshold(ch1[i], ch1[i], 20, 255, CV_THRESH_BINARY);
    }

    for(i=1;i<10;i++){
                      per[i]=percentagematch(num[i],numtemp[i]);
                      }
    for(i=1;i<27;i++){
                      per[i+9]=percentagematch(ch[i],chartemp[i]);//function explained above
                      }
    for(i=1;i<27;i++){                                            //recording percentage matching with each character
                      per[i+35]=percentagematch(ch1[i],char1temp[i]);
                      }
    
    
    
    
    
    for(i=1;i<62;i++)
    {
                    if(maxper<per[i])
                    {
                                     maxper=per[i];
                                     numb=(i);
                    
                    }
                    }
                    if(maxper >50.0 && numb<10){
                                    result[b]=numb+'0';
                                    xcor[b]=(it->second->centroid.x);//per[1-9] is for no. 1-9,per[10-35] is for capital letter,&per[36-61]is for small letters
                                    ycor[b]=(it->second->centroid.y);//here we are storing the corresponding no. with maxpar match in array result& x&y co-odinate of centroid of blob
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
                                                     swap(result[i],result[j]); //swaping coordinate according to their x & y coordinate
                                                     swap(ycor[i],ycor[j]);     //this is done as the laveling of blobs according to their y cordinate and if the string is slightly inverted then it will print he blob which is on upper side
                                  }                  
                }                
}
i=0;
while(i<b){
                 if(abs(ycor[i]-ycor[i+1])<20&&(i+1)<b){//printing the stored array
                 printf("%c",result[i]);               //condition of ycor is to print the blobs in next line which is in next line
                 i++;
                 }
                 else{
                      printf("%c",result[i]);
                      printf("\n");
                      i++;
                      }
                 
                 
                 }
                 

    
   
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvReleaseImage(&imgOut);
    cvReleaseImage(&grey);
    for(i=1;i<10;i++){
                     cvReleaseImage(&num[i]);
                     cvReleaseImage(&numtemp[i]);
                     }//releasing of each image and blob is important
    for(i=1;i<27;i++){
                     cvReleaseImage(&ch[i]);
                     cvReleaseImage(&chartemp[i]);
                     }
    for(i=1;i<27;i++){
                     cvReleaseImage(&ch1[i]);
                     cvReleaseImage(&char1temp[i]);
                     }
    cvReleaseImage(&labelImg);
    cvReleaseCapture(&capture);
    cvReleaseBlobs(blobs);
    
}

    

