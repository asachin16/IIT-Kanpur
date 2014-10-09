#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cvblob.h>
#include "cvblob.cpp"
#include "cvlabel.cpp"
using namespace cvb;

 IplImage* image;
 IplImage* grey;
 IplImage* imgOut;
 float cfactor=20/60;
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

static CvSubdiv2D* init_delaunay( CvMemStorage* storage,
                           CvRect rect )
{
    CvSubdiv2D* subdiv;

    subdiv = cvCreateSubdiv2D( CV_SEQ_KIND_SUBDIV2D, sizeof(*subdiv),
                               sizeof(CvSubdiv2DPoint),
                               sizeof(CvQuadEdge2D),
                               storage );
    cvInitSubdivDelaunay2D( subdiv, rect );

    return subdiv;
}


static void draw_subdiv_point( IplImage* img, CvPoint2D32f fp, CvScalar color )
{
    cvCircle( img, cvPoint(cvRound(fp.x), cvRound(fp.y)), 3, color, CV_FILLED, 8, 0 );
}


static void draw_subdiv_edge( IplImage* img, CvSubdiv2DEdge edge, CvScalar color )
{
    CvSubdiv2DPoint* org_pt;
    CvSubdiv2DPoint* dst_pt;
    CvPoint2D32f org;
    CvPoint2D32f dst;
    CvPoint iorg, idst;

    org_pt = cvSubdiv2DEdgeOrg(edge);
    dst_pt = cvSubdiv2DEdgeDst(edge);

    if( org_pt && dst_pt )
    {
        org = org_pt->pt;
        dst = dst_pt->pt;

        iorg = cvPoint( cvRound( org.x ), cvRound( org.y ));
        idst = cvPoint( cvRound( dst.x ), cvRound( dst.y ));

        cvLine( img, iorg, idst, color, 1, CV_AA, 0 );
    }
}


static void draw_subdiv( IplImage* img, CvSubdiv2D* subdiv,
                  CvScalar delaunay_color, CvScalar voronoi_color )
{
    CvSeqReader  reader;
    int i, total = subdiv->edges->total;
    int elem_size = subdiv->edges->elem_size;

    cvStartReadSeq( (CvSeq*)(subdiv->edges), &reader, 0 );

    for( i = 0; i < total; i++ )
    {
        CvQuadEdge2D* edge = (CvQuadEdge2D*)(reader.ptr);

        if( CV_IS_SET_ELEM( edge ))
        {
            draw_subdiv_edge( img, (CvSubdiv2DEdge)edge + 1, voronoi_color );
            draw_subdiv_edge( img, (CvSubdiv2DEdge)edge, delaunay_color );
        }

        CV_NEXT_SEQ_ELEM( elem_size, reader );
    }
}


static void locate_point( CvSubdiv2D* subdiv, CvPoint2D32f fp, IplImage* img,
                   CvScalar active_color )
{
    CvSubdiv2DEdge e;
    CvSubdiv2DEdge e0 = 0;
    CvSubdiv2DPoint* p = 0;

    cvSubdiv2DLocate( subdiv, fp, &e0, &p );

    if( e0 )
    {
        e = e0;
        do
        {
            draw_subdiv_edge( img, e, active_color );
            e = cvSubdiv2DGetEdge(e,CV_NEXT_AROUND_LEFT);
        }
        while( e != e0 );
    }

    draw_subdiv_point( img, fp, active_color );
}


static void draw_subdiv_facet( IplImage* img, CvSubdiv2DEdge edge )
{
    CvSubdiv2DEdge t = edge;
    int i, count = 0;
    CvPoint* buf = 0;

    // count number of edges in facet
    do
    {
        count++;
        t = cvSubdiv2DGetEdge( t, CV_NEXT_AROUND_LEFT );
    } while (t != edge );

    buf = (CvPoint*)malloc( count * sizeof(buf[0]));

    // gather points
    t = edge;
    for( i = 0; i < count; i++ )
    {
        CvSubdiv2DPoint* pt = cvSubdiv2DEdgeOrg( t );
        if( !pt ) break;
        buf[i] = cvPoint( cvRound(pt->pt.x), cvRound(pt->pt.y));
        t = cvSubdiv2DGetEdge( t, CV_NEXT_AROUND_LEFT );
    }

    if( i == count )
    {
        CvSubdiv2DPoint* pt = cvSubdiv2DEdgeDst( cvSubdiv2DRotateEdge( edge, 1 ));
        cvFillConvexPoly( img, buf, count, CV_RGB(rand()&255,rand()&255,rand()&255), CV_AA, 0 );
        cvPolyLine( img, &buf, &count, 1, 1, CV_RGB(0,0,0), 1, CV_AA, 0);
        draw_subdiv_point( img, pt->pt, CV_RGB(0,0,0));
    }
    free( buf );
}

static void paint_voronoi( CvSubdiv2D* subdiv, IplImage* img )
{
    CvSeqReader  reader;
    int i, total = subdiv->edges->total;
    int elem_size = subdiv->edges->elem_size;

    cvCalcSubdivVoronoi2D( subdiv );

    cvStartReadSeq( (CvSeq*)(subdiv->edges), &reader, 0 );

    for( i = 0; i < total; i++ )
    {
        CvQuadEdge2D* edge = (CvQuadEdge2D*)(reader.ptr);

        if( CV_IS_SET_ELEM( edge ))
        {
            CvSubdiv2DEdge e = (CvSubdiv2DEdge)edge;
            // left
            draw_subdiv_facet( img, cvSubdiv2DRotateEdge( e, 1 ));

            // right
            draw_subdiv_facet( img, cvSubdiv2DRotateEdge( e, 3 ));
        }

        CV_NEXT_SEQ_ELEM( elem_size, reader );
    }
}


static void run(void)
{
    char win[] = "source";
    int i;
    CvRect rect = { 0, 0, 600, 600 };
    CvMemStorage* storage;
    CvSubdiv2D* subdiv;
    IplImage* img;
    CvScalar active_facet_color, delaunay_color, voronoi_color, bkgnd_color;

    active_facet_color = CV_RGB( 255, 0, 0 );
    delaunay_color  = CV_RGB( 0,0,0);
    voronoi_color = CV_RGB(0, 180, 0);
    bkgnd_color = CV_RGB(255,255,255);

    img = cvCreateImage( cvGetSize(image), 8, 3 );
    cvSet( img, bkgnd_color, 0 );

    cvNamedWindow( win, 1 );

    storage = cvCreateMemStorage(0);
    subdiv = init_delaunay( storage, rect );

    printf("Delaunay triangulation will be build now interactively.\n"
           "To stop the process, press any key\n\n");

    for( i = 0; i < 200; i++ )
    {
        CvPoint2D32f fp = cvPoint2D32f( (float)(rand()%(rect.width-10)+5),
                                        (float)(rand()%(rect.height-10)+5));

        locate_point( subdiv, fp, img, active_facet_color );
        cvShowImage( win, img );

        if( cvWaitKey( 100 ) >= 0 )
            break;

        cvSubdivDelaunay2DInsert( subdiv, fp );
        cvCalcSubdivVoronoi2D( subdiv );
        cvSet( img, bkgnd_color, 0 );
        draw_subdiv( img, subdiv, delaunay_color, voronoi_color );
        cvShowImage( win, img );

        if( cvWaitKey( 100 ) >= 0 )
            break;
    }

    cvSet( img, bkgnd_color, 0 );
    paint_voronoi( subdiv, img );
    cvShowImage( win, img );

    cvWaitKey(0);

    cvReleaseMemStorage( &storage );
    cvReleaseImage(&img);
    cvDestroyWindow( win );
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
     int area;
     int x[200],y[200];
     int i=0;
      IplImage* labelImg;
      imgOut=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
      labelImg=cvCreateImage(cvGetSize(image),IPL_DEPTH_LABEL,1);
      CvBlobs blobs;
      cvLabel(grey, labelImg, blobs);
      cvFilterByArea(blobs,500,100000);
      cvRenderBlobs(labelImg, blobs, image, imgOut,CV_BLOB_RENDER_COLOR);
      cvShowImage("blobs",imgOut);
      cvShowImage("Binary_image",grey);
      cvWaitKey(0);  
       for(CvBlobs::const_iterator it=blobs.begin();it!=blobs.end();++it)
    {
         area=it->second->area;
         //printf("%d\n",area);
		 x[i]=(int)it->second->centroid.x;
		 y[i]=(int)it->second->centroid.y; 
         printf("%d \t %d \n",x[i],y[i]);
		 fprintf(fb,"%d \t %d \n",x[i],y[i]);   
		 i++;                     
    }    
}

void correction_factor(){
     int lengthp,lengthm;
     IplImage* img1;
     img1=cvLoadImage("D2-4-1000x.jpg",1);
     cvNamedWindow("image",1);
     cvSetMouseCallback( "image", mouseHandler, img1 );
     cvShowImage( "image", img1 );
     cvWaitKey(0);
     printf("Enter size in Pixcels\n");
     scanf("%d",&lengthp);
     printf("Enter size in Microns\n");
     scanf("%d",&lengthm);
     cfactor = (float)lengthm/lengthp;
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
    //correction_factor();
    image=cvLoadImage("D2-5-10000x.png",1);
    cvShowImage("image1",image);
    grey=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,1);
    cvCvtColor(image, grey, CV_BGR2GRAY);
    cvThreshold(grey, grey,60, 255, CV_THRESH_BINARY_INV);
    Grain_size();
    final_binary();
    cvShowImage("imgout",imgOut);
    cvSaveImage("D2-4-1000x_b.png",imgOut);
    fclose(fb);
    fclose(fp);
    //cvWaitKey(0);
    //for(i=50;i<250;i++)
    //agglomuration(i);
    

    cvWaitKey(0);
    return 0;   
}
