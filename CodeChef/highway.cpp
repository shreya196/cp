#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<long long int ,long long int> ipair;
long long int n,m,s,e;
long long int  dist[100001];
list< pair<long long int,long long int> > adj[100001];
void addedge(long long int u,long long int v,long long int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}
void shortest(long long int n,long long int s,long long int e)
{
	long long int j;
	//cout<<"i am in shortest function"<<endl;
    for(j=0;j<n;j++)
    {
    	dist[j]=INF;
    }
	priority_queue<ipair ,vector <ipair> ,greater<ipair> > pq;
	pq.push(make_pair(0,s));
	dist[s]=0;
	//cout<<dist[s]<<endl;
	//res=0;
	while(!pq.empty())
	{
		long long int u=pq.top().second;
		pq.pop();
		/*if(u==e)
		{
			res=dist[u];
			break;
		}*/
			//cout<<u<<endl;
		list< pair<long long int,long long int > > ::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();++i)
		{
			long long int a=(*i).first;
			long long int b=(*i).second;
			if(dist[a]>dist[u]+b)
			{
				dist[a]=dist[u]+b;
				pq.push(make_pair(dist[a],a));
			}

		}

	}
	//cout<<e<<endl;
	if(dist[e]==INF)
		cout<<"NONE"<<endl;
	else
	cout<<dist[e]<<endl;
}
int main()
{
	long long int q,i,u,v,w;
	cin>>q;
	while(q--)
	{   
		//res=0;

		cin>>n>>m>>s>>e;
		for(i=0;i<m;i++)
		{
         cin>>u>>v>>w;
         addedge(u-1,v-1,w);
         //addedge(v-1,u,w);
		}

        
        	shortest(n,s-1,e-1);
            //res=dist[e];
              
        
        //cout<<res<<endl;
	}
}
