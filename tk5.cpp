#include <bits/stdc++.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;
Mat img=imread("out10.png",0);
Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
Mat img3(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
float squarert(int x1,int x2,int y1,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void ld()
{
	int i,j,k,x1,y1,max=0;
	//Mat img3(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	vector<Point> v;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j)==255) v.push_back(Point(i,j));
		}
	}
	vector<Vec4i> lines1;
	HoughLinesP( img, lines1, 1, CV_PI/180,10, 1, 10 );
	float slope[lines1.size()];
	int b[lines1.size()];
	for( size_t i = 0; i < lines1.size(); i++ )
    {
    	b[i]=0;
    	slope[i]=(float)(lines1[i][2]-lines1[i][0])/(lines1[i][3]-lines1[i][1]);
    	if(abs(slope[i])<5/*&&squarert(lines[i][2],lines[i][0],lines[i][3],lines[i][1])>3*/)
    	{
    		b[i]=1;
    		line(img2,Point(lines1[i][0],lines1[i][1]),Point(lines1[i][2],lines1[i][3]),Scalar(0,0,255), 1, 1);
    		/*for(k=0;k<img3.rows;k++)
   			{
    		
    			int c=slope[i]*(k-lines[i][1])+lines[i][0];
    			if(c<img3.cols&&c>0) 
    				{
    					img3.at<Vec3b>(k,c)[2]+=20;

    				}    		
    		}*/	
    	} 
	
    }
	for( size_t i = 0; i < lines1.size(); i++ )
    {
    	for(j=i+1;j<lines1.size();j++)
    	{
    		float w=(float)(lines1[j][0]-lines1[i][0])/(lines1[j][1]-lines1[i][1]);	
    		if(abs(atan(slope[i])-atan(slope[j]))<0.005&&abs(atan(slope[i])-atan(w))<0.005)
    		{
    			line(img2,Point(lines1[i][0],lines1[i][1]),Point(lines1[j][0],lines1[j][1]),Scalar(0,0,255), 1, 1);    		}
    	}
    }
    imshow("win",img3);
    /*for(i=0;i<img3.rows;i++)
    {
    	for(j=0;j<img3.cols;j++)
    	{
    		if(max<img3.at<Vec3b>(i,j)[2])
    		{
    			max=img3.at<Vec3b>(i,j)[2];
    			x1=i;
    			y1=j;
    		}
    	}
    }
    int l=1;
    int a[img.rows][img.cols];
    int c[img.rows][img.cols];
    //cout<<img.rows<<" "<<img.cols<<endl;
    for(i=0;i<img.rows;i++)
    {
    	for(j=0;j<img.cols;j++)
    	{
    		a[i][j]=0;
    		c[i][j]=0;
    	}
    }
    for(size_t i=0;i<lines.size()-1;i++)
    {
    	if(slope[i]!=-1)
    	{
    		for(size_t j=i+1;j<lines.size();j++)
    		{
    			//int x=(float)(lines[j][0]-lines[i][0])/(lines[j][1]-lines[i][1]);
    			if(abs(atan(slope[i])-atan(slope[j]))<CV_PI/60) slope[j]=-1;
    		}
    	}
    }


   	for(j=0;j<v.size();j++)
   	{
   		float h=10;
   		for(size_t i=0;i<lines.size();i++)
		{
			if(slope[i]!=-1)
			{
				float w=(float)(y1-v[j].y)/(x1-v[j].x);
				if(abs(atan(w)-atan(slope[i]))<h)
				{
					h=abs(atan(w)-atan(slope[i]));
					a[v[j].x][v[j].y]=i+1;
				}
			}
		}   		
   	}
    
    int d=0;
    for(j=1;j<lines.size()+1;j++)
    {
    	d+=20;
    	for(i=0;i<img2.rows;i++)
    	{
    		for(k=0;k<img2.cols;k++)
    		{
    			if(a[i][k]==j) img2.at<Vec3b>(i,k)[j%3]=j*20;
    		}
    	}
    }*/
    return;
}

int main()
{
    int i=img.rows,j,l;
    Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
    Mat img4(img.rows,img.cols,CV_8UC1,Scalar(0));
	ld();
    namedWindow("win1",WINDOW_NORMAL);
    namedWindow("win",WINDOW_NORMAL);
    imshow("win1",img2);
    waitKey(0);
	return 0;
}