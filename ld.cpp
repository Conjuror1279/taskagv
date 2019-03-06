#include <bits/stdc++.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;
	Mat img=imread("0000000024.png",1);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img4;
	Mat img5=img.clone();
	Mat img6=img.clone();
float squarert(int x1,int x2,int y1,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void hgt(int t,void* a)
{
	img5=img6.clone();
	int i,j,z=img5.cols-1,x,y,k;
	Mat img3(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	vector<Vec4i> lines;
	HoughLinesP( img2, lines, 1, CV_PI/180,46, 20, 15 );
	float slope[lines.size()];
	int b[lines.size()];
    for( size_t i = 0; i < lines.size(); i++ )
    {
    	b[i]=0;
    	slope[i]=(float)(lines[i][2]-lines[i][0])/(lines[i][3]-lines[i][1]);
    	if(abs(slope[i])<5/*&&squarert(lines[i][2],lines[i][0],lines[i][3],lines[i][1])>40*/)
    	{
    		b[i]=1;	
    	} 
     	
    }
    for(i=0;i<img3.rows;i++)
    {
    	
    		for(k=0;k<lines.size();k++)
    		{
    			int c=slope[k]*(i-lines[k][1])+lines[k][0];
    			if(c<img3.cols&&c>0) 
    				{
    					img3.at<Vec3b>(i,c)[2]+=20;

    				}
    		}
    
    }
    int p=0;
    for(i=img3.rows-1;i>=0;i--)
    {
    	for(j=img3.cols-1;j>=0;j--)
    	{
    		if(p<img3.at<Vec3b>(i,j)[2]&&img3.at<Vec3b>(i,j)[1]==0&&img3.at<Vec3b>(i,j)[0]==0)
    		{
    			x=i;
    			y=j;
    			p=img3.at<Vec3b>(i,j)[2];
    		}
    	}
    }
    for(size_t j=0;j<lines.size();j++)
    {
    	if(b[j]==1)
    	{
    		int c=slope[j]*(x-lines[j][1])+lines[j][0];
    		if(abs(c-y)<10)
    		line( img5, Point(lines[j][0], lines[j][1]),Point(c,x), Scalar(0,0,255), 3, 8 );
    	}
    }
	for(j=0;j<img.cols;j++)
	{
		if(img5.at<Vec3b>(img5.rows-1,j)[2]==255) z=j;
	}
	imshow("win",img5);
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

	//imgsegment(img2);
	imshow("win1",img2);
	imshow("win3",img);
	imwrite("test5.png",img2);
	createTrackbar("tr","win",&t,50,hgt);
	//hgt(1);
	waitKey(0);
		
    return 0;
}