
#include<bits/stdc++.h>
#define inRange(x, y) (m >= 0 && m < 8 && n >= 0 && n < 8)
using namespace std;
int x[10]={-1,-1,-2,-2,2,2,1,1};
int y[10]={-2,2,-1,1,-1,1,-2,2};
int sum[10][10];
int bfs(int a,int b,int c,int d)
{
	int i,j,m,n;
	pair<int,int>p1;
	queue< pair<int,int> >q;
		p1.first=a;
	p1.second=b;	
	q.push(p1);
	

        //sum[a1][b1]=0;
	while(!q.empty())
	{
		p1=q.front();
		q.pop();
			
	/*	if(p1.first==a2 && p1.second==b2)
		{
			return sum[a2][b2];
		}
		*/
			for(i=0;i<8;i++)
			{
				m=p1.first+x[i];
				n=p1.second+y[i];
				if(inRange(m,n)&&sum[m][n]>sum[p1.first][p1.second]+p1.first*m+p1.second*n )
				{
	
					sum[m][n]=sum[p1.first][p1.second]+p1.first*m+p1.second*n;
					q.push(make_pair(m,n));
				}
			
       }
				}	
		   if(sum[c][d] == 9999) 
		   return -1;
		   else
		   return sum[c][d];
}
void init()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
		sum[i][j]=9999;
		}
		}
}
int main()
	{
		int a,b,c,d;
		while(scanf("%d %d %d %d",&c,&a,&d,&b)!=EOF)
		{
			init();
			sum[c][a]=0;
			cout<<bfs(c,a,d,b)<<endl;
		}
	}
