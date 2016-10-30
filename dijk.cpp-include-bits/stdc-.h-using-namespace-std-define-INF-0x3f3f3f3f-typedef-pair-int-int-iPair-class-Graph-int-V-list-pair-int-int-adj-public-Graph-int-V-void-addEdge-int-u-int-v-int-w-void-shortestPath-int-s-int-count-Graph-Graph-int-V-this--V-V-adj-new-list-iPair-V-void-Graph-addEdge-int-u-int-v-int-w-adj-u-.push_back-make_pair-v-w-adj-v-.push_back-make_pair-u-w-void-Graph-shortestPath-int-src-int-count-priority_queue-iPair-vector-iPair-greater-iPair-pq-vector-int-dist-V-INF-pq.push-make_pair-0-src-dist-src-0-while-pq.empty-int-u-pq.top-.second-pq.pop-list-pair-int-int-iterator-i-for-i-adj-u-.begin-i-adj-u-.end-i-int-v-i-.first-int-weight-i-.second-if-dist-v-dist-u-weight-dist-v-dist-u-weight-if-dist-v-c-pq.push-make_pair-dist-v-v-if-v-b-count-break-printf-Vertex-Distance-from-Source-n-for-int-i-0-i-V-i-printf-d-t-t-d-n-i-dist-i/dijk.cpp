#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
 

typedef pair<int, int> iPair;
class Graph
{
    int V;    
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  
    void addEdge(int u, int v, int w);
 
    void shortestPath(int s,int count);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::shortestPath(int src,int count)
{
   
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    vector<int> dist(V, INF);
 
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
 
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
           
            int v = (*i).first;
            int weight = (*i).second;
 
         
            if (dist[v] > dist[u] + weight)
            {
                
                dist[v] = dist[u] + weight;
                if(dist[v]<=c)
                {
                pq.push(make_pair(dist[v], v));
                }
                if(v==b)
                {
                    count++;
                    break;
                }
            }
        }
    }
 
 
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// Driver program to test methods of graph class
int main()
{
    int a,b,c,d,count;
    int V = 9;
    count=0;
    int m,n,p;
    Graph g(V);
    cin>>a>>b>>c>>d;
    for(int i=0;i<d;i++)
    {
        cin>>m>>n>>p;
    g.addEdge(m, n, p);
    
 }
   for (int i = 0; i <a; ++i)
   {
        g.shortestPath(i,count);
   }

   printf(" mice are %d",count);
 
    return 0;
}
