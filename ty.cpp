#include <bits/stdc++.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;
	Mat img=imread("0000000074.png",1);
	Mat img4;
	Mat img5=img.clone();
	Mat img6(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
float squarert(int x1,int x2,int y1,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

/*void imgsegment(Mat img2)
{
	int i,j;
	img1=img2.clone();
	for(i=0;i<img2.cols;i++)
	{
		for(j=0;j<3*img2.rows/4;j++)
		{
			img1.at<uchar>(i,j)=0;
		}
	}
	return;
}*/

void ld(Mat img2)
{
	int i,j,k,x1,y1,max=0;
	//Mat img;
	//img=imread("out26.png",0);
	Mat img3(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	//Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	vector<Point> v;
	for(i=0;i<img2.rows;i++)
	{
		for(j=0;j<img2.cols;j++)
		{
			if(img2.at<uchar>(i,j)==255) v.push_back(Point(i,j));
		}
	}
	vector<Vec4i> lines;
	HoughLinesP( img2, lines, 1, CV_PI/180,20, 15, 15 );
	float slope[lines.size()];
	int b[lines.size()];
	for( size_t i = 0; i < lines.size(); i++ )
    {
    	b[i]=0;
    	slope[i]=(float)(lines[i][2]-lines[i][0])/(lines[i][3]-lines[i][1]);
    	if(abs(slope[i])<5&&squarert(lines[i][2],lines[i][0],lines[i][3],lines[i][1])>10)
    	{
    		b[i]=1;
    		for(k=0;k<img3.rows;k++)
   			{
    		
    			int c=slope[i]*(k-lines[i][1])+lines[i][0];
    			if(c<img3.cols&&c>0) 
    				{
    					img3.at<Vec3b>(k,c)[2]+=20;

    				}    		
    		}	
    	} 
     	
    }
    for(i=0;i<img3.rows;i++)
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
    for(size_t i=0;i<lines.size();i++)
   	{
   		if(a[lines[i][1]][lines[i][0]]==0)
   		{
   		for(j=0;j<v.size();j++)
		{

			
				float w=(float)(y1-v[j].y)/(x1-v[j].x);
				if(abs(atan(w)-atan(slope[i]))<0.1)
				{
					a[v[j].x][v[j].y]=1;
				}
			
		}
		}   		
   	}
    
    int d=0;
    	for(i=0;i<img2.rows;i++)
    	{
    		for(k=0;k<img2.cols;k++)
    		{
    			if(a[i][k]==1) img1.at<Vec3b>(i,k)[2]=100;
    		}
    	}
	for( size_t i = 0; i < lines.size(); i++ )
    {
    	if(squarert(lines[i][2],lines[i][0],lines[i][3],lines[i][1])>10)
    	{
    		int c=slope[i]*(x1-lines[i][1])+lines[i][0];
    		if(abs(c-y1)<10&&a[lines[i][1]][lines[i][0]]==1)
    		line(img5,Point(lines[i][0],lines[i][1]),Point(lines[i][2],lines[i][3]),Scalar(0,0,255), 3, 8);	
    	} 
     	
    }
    return;
}


int main()
{
	int x,b;
	cin>>x;
	int max=0;
	int t1,i,j,k,t;
	/*for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			if(abs(img.at<Vec3b>(i,j)[2]-img.at<Vec3b>(i,j)[0])<9&&abs(img.at<Vec3b>(i,j)[1]-img.at<Vec3b>(i,j)[0])<9) continue;
			else img.at<Vec3b>(i,j)={0,0,0};
		}*/
	cvtColor(img,img,CV_BGR2GRAY);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=1;i<img.rows-1;i++)
		for(j=1;j<img.cols-1;j++)
		{
			if(max<img.at<uchar>(i,j)) max=img.at<uchar>(i,j);
			img2.at<uchar>(i,j)=img.at<uchar>(i-1,j-1)/16+img.at<uchar>(i-1,j)/8+img.at<uchar>(i-1,j+1)/16+img.at<uchar>(i,j-1)/8+img.at<uchar>(i,j)/4+img.at<uchar>(i,j+1)/8+img.at<uchar>(i+1,j-1)/16+img.at<uchar>(i+1,j)/8+img.at<uchar>(i+1,j+1)/16;
		}
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			b=img.at<uchar>(i-1,j-1)-img.at<uchar>(i-1,j+1)+img.at<uchar>(i,j-1)-img.at<uchar>(i,j+1)+img.at<uchar>(i+1,j-1)-img.at<uchar>(i+1,j+1);
			if(b>x) continue;
			else img2.at<uchar>(i,j)=0;
		}
	namedWindow("win",WINDOW_NORMAL);
	namedWindow("win1",WINDOW_NORMAL);
	namedWindow("win3",WINDOW_NORMAL);
	//createTrackbar("tra","win1",&t1,255);
	img4=img2.clone();
	
	//setMouseCallback("win",callback_fn,NULL);
	
	
	
		for(i=1;i<img.rows-1;i++)
				for(j=1;j<img.cols-1;j++)
				{
					if(img4.at<uchar>(i,j)>(max)/2) img2.at<uchar>(i,j)=255;
					else img2.at<uchar>(i,j)=0; 
				}
		//imshow("win1",img2);
		//waitKey(0);	
	img=img2.clone();
	Canny(img2,img,75,255,3);
	vector<Point> v;
	v.push_back(Point(0,img.rows));
	v.push_back(Point(img.cols/3,img.rows/2));
	v.push_back(Point(((img.cols*2)/3),img.rows/2));
	v.push_back(Point(img.cols,img.rows));
	fillConvexPoly(img2,v,Scalar(100.0),8);
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			if(img2.at<uchar>(i,j)==100)
			{
				img2.at<uchar>(i,j)=img.at<uchar>(i,j);
			}
			else img2.at<uchar>(i,j)=0;
		}
	//img1(img2.rows,img2.cols,CV_8UC1,Scalar(0));
	/*img1=img2.clone();
	for(i=0;i<img1.cols;i++)
	{
		for(j=0;j<(3*img1.rows)/4;j++)
		{
			img1.at<uchar>(j,i)=0;
		}
	}*/
		int l=0;
	for(k=1;k<11;k++)
	{
		img1=img6.clone();
		for(i=l;i<k*img.rows/10;i++)
		{
			for(j=0;j<img.cols;j++)
			{
				img1.at<uchar>(i,j)=img2.at<uchar>(i,j);
			}
		}
		l=i;
		ld(img1);
	}
	
	imshow("win1",img2);
	imshow("win3",img5);
	//createTrackbar("tr","win",&t,50,hgt);
	
	waitKey(0);
		
    return 0;
}