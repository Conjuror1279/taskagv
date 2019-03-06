#include <bits/stdc++.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat img=imread("road.jpg",0);
Mat img1;
Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
/*void tr(int t,void* a)
{
	int i,j;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j)>t) img.at<uchar>(i,j)=255;
			else img.at<uchar>(i,j)=0;
		}
	}
	imshow("win",img);
}*/

/*void on_trackbar(int t,void*)
{
	int i,j,i1,j1,b;
	for(i=0;i<img1.rows;i++)
	{
		for(j=0;j<img1.cols;j++)
		{
			if(img1.at<uchar>(i,j)>=t)
			{
				for(i1=0;i1<img.rows;i1++)
				{
					for(j1=0;j1<img.cols;j1++)
					{
						b=abs(i1*cos(j*3.14/180)+j1*sin(j*3.14/180));
						if(b==i) img3.at<uchar>(i1,j1)==255;
					}
				}
			}
		}
	}
	imshow("win",img3);
}*/

int main()
{
	int i,j,t,k,r;
	//img;
	Mat img2;
	Mat img1(img.rows+img.cols,180,CV_8UC1,Scalar(0));
	//img3(img.rows,img.cols,CV_8UC1,Scalar(0));
	namedWindow("win",WINDOW_NORMAL);
	Canny(img,img2,100,255,3);
	for(i=0;i<img2.rows;i++)
		for(j=0;j<img2.cols;j++)
		{
			if(img2.at<uchar>(i,j)==255)
			{
				for(k=0;k<180;k++)
				{
					r=abs(i*cos((k)*3.14/180)+j*sin((k)*3.14/180));
					img1.at<uchar>(r,k)+=1;					
				}
			}
			
		}
		namedWindow("win1",WINDOW_NORMAL);
	imshow("win1",img1);
	int i1,j1,b;		
	for(i=0;i<img1.rows;i++)
	{
		for(j=0;j<img1.cols;j++)
		{
			if(img1.at<uchar>(i,j)>=10)
			{
				for(i1=0;i1<img.rows;i1++)
				{
					for(j1=0;j1<img.cols;j1++)
					{
						b=abs(i1*cos(j*3.14/180)+j1*sin(j*3.14/180));
						if(b==i) img3.at<uchar>(i1,j1)==255;
					}
				}
			}
		}
	}
	imshow("win",img3);
	waitKey(0);
	
	
	//tr(t,0);
	waitKey(0);
	
    return 0;
}