#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<bits/stdc++.h>

using namespace std;
using namespace cv;
int z=0,b=0,x,y;
Mat img1=imread("21.png",1);
	Mat img(img1.rows,img1.cols,CV_8UC1,Scalar(0));
int bb;
Mat img2;
float g[3000][3000];
int a[3000][3000];
float squarert(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
float manhatten(int x1,int y1,int x2 ,int y2)
{
	return abs(x2-x1)+abs(y2-y1);
}
float fn(int p,int b)
{
	return squarert(p,b,x,y)+g[p][b];
}
void Astar()
{
	vector<Point>open;
	vector<Point>closed;
	vector<pair<float,Point>>dist;
	int i,j,k=0;
	int x1,y1;
	g[z][b]=0;
	g[x][y]=0;
	int o=0;
	open.push_back(Point(z,b));
	dist.push_back(fn(z,b));
	cout<<open.size()<<endl;
	while(open.size())
	{
		sort(dist.begin(),dist.end());
		x1=dist[0].second.x;
		y1=dist[0].second.y;

		img.at<uchar>(x1,y1)=100;
		imshow("win",img);
		waitKey(1);
		//open.erase(open.begin()+find(open.begin(), open.end(), Point(x1,y1)) );
		open.erase(open.begin()+k);
		closed.push_back(Point(x1,y1));
		cout<<x1<<" "<<y1<<"  ";
		//if(squarert(x1,y1,y,x)<0) break;
		if(y1==y&&x1==x)
		{

			break;
			o=1;
			
		}
		
				if(a[x1-1][y1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1-1,y1)) != open.end())
					{
						if(g[x1-1][y1]>g[x1][y1]+1) g[x1-1][y1]=g[x1][y1]+1;
					}
					else if(find(closed.begin(), closed.end(), Point(x1-1,y1)) != closed.end())
					{
						if(g[x1-1][y1]>g[x1][y1]+1){ g[x1-1][y1]=g[x1][y1]+1;
						//closed.erase(closed.begin()+find(closed.begin(), closed.end(), Point(x1-1,y1)));
						closed.erase(remove(closed.begin(), closed.end(), Point(x1-1,y1)), closed.end());

						open.push_back(Point(x1-1,y1));
						dist.push_back(make_pair(fn(x1-1,y1),Point(x1-1,y1)));}
					}
					else if(g[x1-1][y1]==bb)
					{
						g[x1-1][y1]=g[x1][y1]+1;
						open.push_back(Point(x1-1,y1));
						dist.push_back(make_pair(fn(x1-1,y1),Point(x1-1,y1)));
					}

				}
			if(a[x1][y1-1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1,y1-1)) != open.end())
					{
						if(g[x1][y1-1]>g[x1][y1]+1) g[x1][y1-1]=g[x1][y1]+1;
					}
					else if(find(closed.begin(), closed.end(), Point(x1,y1-1)) != closed.end())
					{
						if(g[x1][y1-1]>g[x1][y1]+1){ g[x1][y1-1]=g[x1][y1]+1;
						closed.erase(remove(closed.begin(), closed.end(), Point(x1,y1-1)), closed.end());
						open.push_back(Point(x1,y1-1));
						dist.push_back(make_pair(fn(x1,y1-1),Point(x1,y1-1)));}
					}
					else if(g[x1][y1-1]==bb)
					{
						g[x1][y1-1]=g[x1][y1]+1;
						open.push_back(Point(x1,y1-1));
						dist.push_back(make_pair(fn(x1,y1-1),Point(x1,y1-1)));
					}

				}
			if(a[x1+1][y1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1+1,y1)) != open.end())
					{
						if(g[x1+1][y1]>g[x1][y1]+1) g[x1+1][y1]=g[x1][y1]+1;
					}
					else if(find(closed.begin(), closed.end(), Point(x1+1,y1)) != closed.end())
					{
						if(g[x1+1][y1]>g[x1][y1]+1){ g[x1+1][y1]=g[x1][y1]+1;
						closed.erase(remove(closed.begin(), closed.end(), Point(x1-1,y1)), closed.end());
						open.push_back(Point(x1+1,y1));
						dist.push_back(make_pair(fn(x1+1,y1)),Point(x1+1,y1));	}
					}
					else if(g[x1+1][y1]==bb)
					{
						g[x1+1][y1]=g[x1][y1]+1;
						open.push_back(Point(x1+1,y1));
						dist.push_back(make_pair(fn(x1+1,y1)),Point(x1+1,y1));
					}

				}
				if(a[x1][y1+1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1,y1+1)) != open.end())
					{
						if(g[x1][y1+1]>g[x1][y1]+1) g[x1][y1+1]=g[x1][y1]+1;
					}
					else if(find(closed.begin(), closed.end(), Point(x1,y1+1)) != closed.end())
					{
						if(g[x1][y1+1]>g[x1][y1]+1){ g[x1][y1+1]=g[x1][y1]+1;
						//closed.erase(closed.begin()+find(closed.begin(), closed.end(), Point(x1,y1+1)));
						closed.erase(remove(closed.begin(), closed.end(), Point(x1,y1+1)), closed.end());

						open.push_back(Point(x1,y1+1));
						dist.push_back(make_pair(fn(x1,y1+1),Point(x1,y1+1)));}
					}
					else if(g[x1][y1+1]==bb)
					{
						g[x1][y1+1]=g[x1][y1]+1;
						open.push_back(Point(x1,y1+1));
						dist.push_back(make_pair(fn(x1,y1+1),Point(x1,y1+1)));
					}
				}
				if(a[x1-1][y1-1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1-1,y1-1)) != open.end())
					{
						if(g[x1-1][y1-1]>g[x1][y1]+1.41) g[x1-1][y1-1]=g[x1][y1]+1.41;
					}
					else if(find(closed.begin(), closed.end(), Point(x1-1,y1-1)) != closed.end())
					{
						if(g[x1-1][y1-1]>g[x1][y1]+1.41){ g[x1-1][y1-1]=g[x1][y1]+1.41;
						//closed.erase(closed.begin()+find(closed.begin(), closed.end(), Point(x1-1,y1-1)));
						closed.erase(remove(closed.begin(), closed.end(), Point(x1-1,y1-1)), closed.end());

						open.push_back(Point(x1-1,y1-1));
						dist.push_back(make_pair(fn(x1-1,y1-1),Point(x1-1,y1-1)));}
					}
					else if(g[x1-1][y1-1]==bb)
					{
						g[x1-1][y1-1]=g[x1][y1]+1.41;
						open.push_back(Point(x1-1,y1-1));
						dist.push_back(make_pair(fn(x1-1,y1-1),Point(x1-1,y1-1)));
					}

				}
				if(a[x1+1][y1-1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1+1,y1-1)) != open.end())
					{
						if(g[x1+1][y1-1]>g[x1][y1]+1.41) g[x1+1][y1-1]=g[x1][y1]+1.41;
					}
					else if(find(closed.begin(), closed.end(), Point(x1+1,y1-1)) != closed.end())
					{
						if(g[x1+1][y1-1]>g[x1][y1]+1.41){ g[x1+1][y1-1]=g[x1][y1]+1.41;
						//closed.erase(closed.begin()+find(closed.begin(), closed.end(), Point(x1+1,y1-1)));
						closed.erase(remove(closed.begin(), closed.end(), Point(x1+1,y1-1)), closed.end());

						open.push_back(Point(x1+1,y1-1));
						dist.push_back(make_pair(fn(x1+1,y1-1),Point(x1+1,y1-1)));}
					}
					else if(g[x1+1][y1-1]==bb)
					{
						g[x1+1][y1-1]=g[x1][y1]+1.41;
						open.push_back(Point(x1+1,y1-1));
						dist.push_back(make_pair(fn(x1+1,y1-1),Point(x1+1,y1-1)));
					}

				}
				if(a[x1+1][y1+1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1+1,y1+1)) != open.end())
					{
						if(g[x1+1][y1+1]>g[x1][y1]+1) g[x1+1][y1+1]=g[x1][y1]+1.41;
					}
					else if(find(closed.begin(), closed.end(), Point(x1+1,y1+1)) != closed.end())
					{
						if(g[x1+1][y1+1]>g[x1][y1]+1.41){ g[x1+1][y1+1]=g[x1][y1]+1.41;
						//closed.erase(closed.begin()+find(closed.begin(), closed.end(), Point(x1+1,y1+1)));
					closed.erase(remove(closed.begin(), closed.end(), Point(x1+1,y1+1)), closed.end());

						open.push_back(Point(x1+1,y1+1));
						dist.push_back(make_pair(fn(x1+1,y1+1),Point(x1+1,y1+1)));}
					}
					else if(g[x1+1][y1+1]==bb)
					{
						g[x1+1][y1+1]=g[x1][y1]+1.41;
						open.push_back(Point(x1+1,y1+1));
						dist.push_back(make_pair(fn(x1+1,y1+1),Point(x1+1,y1+1)));
					}

				}
				if(a[x1-1][y1+1]==1)
				{
					if(find(open.begin(), open.end(), Point(x1-1,y1+1)) != open.end())
					{
						if(g[x1-1][y1+1]>g[x1][y1]+1.41) g[x1-1][y1+1]=g[x1][y1]+1.41;
					}
					else if(find(closed.begin(), closed.end(), Point(x1-1,y1+1)) != closed.end())
					{
						if(g[x1-1][y1+1]>g[x1][y1]+1.41){ g[x1-1][y1+1]=g[x1][y1]+1.41;
						//closed.erase(closed.begin()+find(closed.begin(), closed.end(), Point(x1-1,y1+1)));
						
						closed.erase(remove(closed.begin(), closed.end(), Point(x1-1,y1+1)), closed.end());


						open.push_back(Point(x1-1,y1+1));
						dist.push_back(make_pair(fn(x1-1,y1+1),Point(x1-1,y1+1)));}
					}
					else if(g[x1-1][y1+1]==bb)
					{
						g[x1-1][y1+1]=g[x1][y1]+1.41;
						open.push_back(Point(x1-1,y1+1));
						dist.push_back(make_pair(fn(x1-1,y1+1),Point(x1-1,y1+1)));
					}

				}
			

	}
	for(i=0;i<closed.size();i++)
	{
		int t1=closed[i].x;
		int t2=closed[i].y;
		img.at<uchar>(t1,t2)=100;
	}
	imshow("win",img);
	waitKey(0);
	if(o==1) return;
	if(x1!=x&&y1!=y) cout<<"no path possible";
	

	
}


int main() 
{
	bb=2*img1.rows*img1.cols;
	int i,j;
	int s,k;
	int sum1=0,sum2=0,sum3=0,sum4=0;
	int i1=0,i2=0;
	cin>>s>>k;
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
	x=sum1/i1;
	y=sum2/i1;
	z=sum3/i2;
	b=sum4/i2;
		
		cvtColor(img1,img,CV_BGR2GRAY);
		threshold(img, img, 160.0, 255, THRESH_BINARY);
		//cout<<x<< " "<<y<<" "<<a<<" "<<b<<endl;	
		//img1.at<Vec3b>(z,b)={254,254,254};
		//img1.at<Vec3b>(x,y)={0,254,254};
		img.at<uchar>(z,b)=100;
		img2=img.clone();	
		cout<<z<<" "<<b<<" "<<x<<" "<<y<<" ";
		/*for(i=0;i<img.rows;i++)
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
		img2=img.clone();*/
		//img=img2.clone();
	/*for(int i=0;i<img2.rows;i++)
		for(int j=0;j<img2.cols;j++)
		{
			if(img2.at<uchar>(i,j)==255) 
				{
					img.at<uchar>(i+k,j+s)=255;img.at<uchar>(i-k,j-s)=255;
				}
		}*/
		for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
		{
			 if(img.at<uchar>(i,j)==255) a[i][j]=0;
			 else a[i][j]=1;
			 g[i][j]=bb;
		}

	namedWindow("win",WINDOW_NORMAL);
	Astar();
	imshow("win",img);
	//imshow("win1",img1);
	waitKey(0);
	
	return 0;
}
