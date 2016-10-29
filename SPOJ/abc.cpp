#include<bits/stdc++.h>
using namespace std;
int X[8]={1,1,0,-1,-1,-1,0,1};
int Y[8]={0,-1,-1,-1,0,1,1,1};
//int count;
char mat[51][51];
int visit[51][51];
int coun=0;
void dfs(int h,int w,int i,int j,int c)
{
	coun=max(coun,c);
	int x,y;
	for(int k=0;k<8;k++)
	 {
		x=i+X[k];
		y=j+Y[k];

		if(x<0 ||x>h||y<0||y>w)
		   continue;

		 else
		 {
		     if(mat[x][y]==mat[i][j]+1 && visit[x][y]!=1)
		      {
		
		        visit[x][y]=1;
		         
		         //cout<<x<<" "<<y<<" "<<c<<endl;
		         dfs(h,w,x,y,c+1);
		         
		          
		 	      

		         

		      }
		       
		 }
		 

	}
    
  
   
   
      //return coun;
     
}
int main()
{
    int q=1;
	while(1)
	{
	    int h,w,i,j,result,max=0;
	    cin>>h>>w;
	    
	    coun=0;
	    
	    if(h==0 && w==0)
	       break;
	    else{
	    
	    for(i=0;i<h;i++)
	      for(j=0;j<w;j++)
	      {
	          cin>>mat[i][j];
	          visit[i][j]=0;

	      }
	      //memset(visit,0,sizeof visit);

	      for(i=0;i<h;i++)
	        for(j=0;j<w;j++)
	         {
	         	
	         	if(mat[i][j]=='A' && visit[i][j]!=1)
	         	  {
	         	  	
	         	  	  
	         	  	  
	         	     //cout<<i<<"  "<<j<<endl;
	         	  	visit[i][j]=1;

	         	   dfs(h,w,i,j,1);
	         	   /* if(max<result)
	         	  	max=result;*/
                   
	         	  }

	         	  

	         	  
	         }

	    }     

	         cout<<"Case"<<" "<<q<<": "<<coun<<endl;
	         q++;
	         //max=0;
	         //result=0;


        
	}
}
