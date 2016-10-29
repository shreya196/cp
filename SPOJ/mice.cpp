#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<long long int ,long long int> ipair;
long long int n,e,t,m,result=0;
list< pair<long long int ,long long int> > adj[1001];
void addedge(long long int u,long long int v,long long int w)
{
  adj[u].push_back(make_pair(v,w));
  //adj[v].push_back(make_pair(u,w));
}
void shortest(long long int s)
{
	priority_queue<ipair ,vector <ipair> ,greater<ipair> > pq;
	vector<long long int> dist(n,INF);
    pq.push(make_pair(0,s));
    dist[s]=0;
    while(!pq.empty())
    {
    	long long int u=pq.top().second;
    	pq.pop();
    	if(u==e)
    	{
    		 if(dist[u]<=m)
        	result++;

    	}
    	list< pair<long long int ,long long int > > ::iterator i;
    	for(i=adj[u].begin();i!=adj[u].end();++i)
    	{
    		long long int a=(*i).first;
    		ong long int b=(*i).second;
    		
    		if(dist[a]>dist[u]+b)
    		{
    			dist[a]=dist[u]+b;
    			pq.push(make_pair(dist[a],a));
    		}
    	

          
        }
       
    }
    //cout<<"all vertices distance from the source"<<endl;
   /* for(int i=0;i<n;i++)
    {
    	cout<<i<<"->"<<dist[i]<<endl;
        
    }*/
}
int main()
{
	long long int i,c,d,ed;
	cin>>n>>e>>m>>t;
	for(i=0;i<t;i++)
		{
           cin>>c>>d>>ed;
           addedge(c-1,d-1,ed);
		}
		for(i=0;i<n;i++)
		{
			shortest(i);
		}
		cout<<result<<endl;
}
