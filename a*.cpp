#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>

using namespace std;
using namespace cv;
Mat img(400,400,CV_8UC1,Scalar(255));
int a[img.rows][img.cols];
int i,j;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j)==0)a[i][j]==10000;
			else a[i][j]=0;
		}
	}

float dist(int i,int j,int a,int b)
{
float h,e;
e=norm(Point(i,j)-Point(a,b));
h=a[i][j];
return h+e;


}
int min (float a[])
{
int k,f;
for(k=0;k<9;k++) if(min>a[k]) {min=a[k];f=k;}
return f;
}

void Astar(int z,int y)
{
k;
float x[9];
x[0]=dist(z-1,y-1,img.rows-1,img.cols-1)+sqrt(2);
x[1]=dist(z,y-1,img.rows-1,img.cols-1)+1;
x[2]=dist(z+1,y-1,img.rows-1,img.cols-1)+sqrt(2);
x[3]=dist(z-1,y,img.rows-1,img.cols-1)+1;
x[4]=dist(z+1,y,img.rows-1,img.cols-1)+1;
x[5]=10000;
x[6]=dist(z-1,y+1,img.rows-1,img.cols-1)+sqrt(2);
x[7]=dist(z,y+1,img.rows-1,img.cols-1)+1;
x[8]=dist(z+1,y+1,img.rows-1,img.cols-1)+sqrt(2);
int k=min (x[8]);
img.at<uchar>(z,y)==100;
if(z!=img.rows||y!=img.cols)
Astar(z+k%3,y+k/3);
else {imshow("win",img);}

}

int main()
{

Astar(1,1);
namedWindow("win",WINDOW_NORMAL);

waitKey(0);
return 0;
}
