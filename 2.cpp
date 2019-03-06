#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<bits/stdc++.h>

using namespace std;
using namespace cv;
int a,b;
Mat img;
Mat img2;

float squarert(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
float manhatten(int x1,int y1,int x2 ,int y2)
{
	return abs(x2-x1)+abs(y2-y1);
}
void Astar(int i,int j)
{
	float z=.414;
	if(i==a&&j==b) return ;
	float min=100000;
	int k=-1,t=-1;
	if(i!=0&&img.at<uchar>(i-1,j)!=255&&(min>manhatten(i-1,j,a,b))&&t!=2)
	 {
	 	min=manhatten(i-1,j,a,b);
	 	k=0;
	 } 
	if(j!=0&&img.at<uchar>(i,j-1)!=255&&(min>manhatten(i,j-1,a,b))&&t!=3)
	 {
	 	min=manhatten(i,j-1,a,b);
	 	k=1;
	 }
	if(i!=img.rows-1&&img.at<uchar>(i+1,j)!=255&&min>manhatten(i+1,j,a,b)&&t!=0) 
	 {
		min=manhatten(i+1,j,a,b);
		k=2;
	 }
	if(j!=img.cols-1&&img.at<uchar>(i,j+1)!=255&&min>manhatten(i,j+1,a,b)&&t!=1)
	 {
	 	min=manhatten(i,j+1,a,b);
	 	k=3;
	 }
	if(i!=0&&j!=0&&img.at<uchar>(i-1,j-1)!=255&&(min>manhatten(i-1,j-1,a,b)+z) &&t!=7)
	 {
	 	min=manhatten(i-1,j-1,a,b)+z;
	 	k=4;
	 }
	if(j!=0&&i!=img.rows-1&&img.at<uchar>(i+1,j-1)!=255&&(min>manhatten(i+1,j-1,a,b)+z)&&t!=6)
	 {
	 	min=manhatten(i+1,j-1,a,b)+z;
	 	k=5;
	 }
	if(i!=0&&j!=img.cols-1&&img.at<uchar>(i-1,j+1)!=255&&(min>manhatten(i-1,j+1,a,b)+z)&&t!=5)
	 {
	 	min=manhatten(i-1,j+1,a,b)+z;
	 	k=6;
	 }
	if(i!=img.rows-1&&j!=img.cols-1&&img.at<uchar>(i+1,j+1)!=255&&(min>manhatten(i+1,j+1,a,b)+z)&&t!=4)
	 {
	   min=manhatten(i+1,j+1,a,b)+z;
	   k=7;
	 }
	imshow("win",img2);
	waitKey(2);
	///cout<<k<<" ";
	
	if(k==0)
	{
		img2.at<uchar>(i-1,j)=100;
		img.at<uchar>(i-1,j)=255;
		return Astar(i-1,j);
	}
	if(k==1)
	{
		img2.at<uchar>(i,j-1)=100;
		img.at<uchar>(i,j-1)=255;
		return Astar(i,j-1);
	}
	if(k==2)
	{
		img2.at<uchar>(i+1,j)=100;
		img.at<uchar>(i+1,j)=255;
		return Astar(i+1,j);
	}
	if(k==3)
	{
		img2.at<uchar>(i,j+1)=100;
		img.at<uchar>(i,j+1)=255;
		return Astar(i,j+1);
	}
	if(k==4)
	{
		img2.at<uchar>(i-1,j-1)=100;
		img.at<uchar>(i-1,j-1)=255;
		return Astar(i-1,j-1);
	}
	if(k==5)
	{
		img2.at<uchar>(i+1,j-1)=100;
		img.at<uchar>(i+1,j-1)=255;
		return Astar(i+1,j-1);
	}
	if(k==6)
	{
		img2.at<uchar>(i-1,j+1)=100;
		img.at<uchar>(i-1,j+1)=255;
		return Astar(i-1,j+1);
	}
	if(k==7)
	{
		img2.at<uchar>(i+1,j+1)=100;
		img.at<uchar>(i+1,j+1)=255;
		return Astar(i+1,j+1);
	}

	
	//if(i=0)
	
}


int main() 
{
	Mat img1=imread("Test1.png",1);
	int i,j;
	int x,y;
	int s,k;
	int sum1=0,sum2=0,sum3=0,sum4=0;
	int i1=0,i2=0;
	cin>>s>>k;
	//imshow("orig", img1);
	//waitKey(0);

	for( i=0;i<img1.rows;i++)
		for( j=0;j<img1.cols;j++)
		{
			if(img1.at<Vec3b>(i,j)[0]==0 && img1.at<Vec3b>(i,j)[1]==0&&img1.at<Vec3b>(i,j)[2]==255)
			 {
			 	i1+=1;
			 	sum1+=i;
			 	sum2+=j;
			 }
			if(img1.at<Vec3b>(i,j)[0]==0 && img1.at<Vec3b>(i,j)[1]==255 && img1.at<Vec3b>(i,j)[2]==0)
			 {
			 	i2+=1;
			 	sum3+=i;
			 	sum4+=j;
			 }
		}
	a=sum1/i1;
	b=sum2/i1;
	x=sum3/i2;
	y=sum4/i2;
	//if(img.at<uchar>(i,j)==255) v[i].push_back()=10000;
	//else v[i].push_back()=0;
		//cout<<sqrt(img.rows*img.rows+img.cols*img.cols)<<endl;
		
		cvtColor(img1,img,CV_BGR2GRAY);
		threshold(img, img, 168.0, 255.0, THRESH_BINARY);
		cout<<x<< " "<<y<<" "<<a<<" "<<b<<endl;	
		img1.at<Vec3b>(a,b)={255,255,255};
		img1.at<Vec3b>(x,y)={255,255,255};
		img.at<uchar>(a,b)=254;
		img2=img.clone();
		for(i=0;i<img.rows;i++)
		{
			for(j=0;j<img.cols;j++)
				{
					if(img2.at<uchar>(i,j)==255) 
					{
						img.at<uchar>(i,j-1)=255;
						img.at<uchar>(i-1,j)=255;
						img.at<uchar>(i,j+1)=255;
						img.at<uchar>(i+1,j)=255;
						img.at<uchar>(i-1,j-1)=255;
						img.at<uchar>(i+1,j-1)=255;
						img.at<uchar>(i-1,j+1)=255;
						img.at<uchar>(i+1,j+1)=255;
					}
				}
		}
		img2=img.clone();
	for(int i=0;i<img2.rows;i++)
		for(int j=0;j<img2.cols;j++)
		{
			if(img2.at<uchar>(i,j)==255) 
				{
					img.at<uchar>(i+k,j+s)=255;img.at<uchar>(i-k,j-s)=255;
				}
		}
	namedWindow("win",WINDOW_NORMAL);
	Astar(x,y);
	imshow("win",img2);
	imshow("win1",img1);
	waitKey(0);
	
	return 0;
}
