#include <bits/stdc++.h>
#define MAX 1000002
#define INF 1000000002

using namespace std;

vector <struct edge> graph1[MAX], graph2[MAX];
long int dist[MAX], done[MAX];

struct edge {
	int v;
	long int price;
} temp;

struct compare  
 {  
   bool operator()(const int& l, const int& r)  
   {  
       return dist[l] > dist[r];
   }  
 }; 

long int dijkstraAll(vector <struct edge> graph[], int s, int n){
	priority_queue<int, vector<int>, compare> q;
	int i, cur;
	long int ans = 0;
	for(i = 1; i <= n; i++){
		dist[i] = INF;
		done[i] = 0;
	}

	dist[s] = 0;
	q.push(s);

	while(!q.empty()){
		cur = q.top();
		q.pop();

		if(done[cur])
			continue;

		for(i = 0; i < graph[cur].size(); i++){
			if(!done[graph[cur][i].v] && dist[graph[cur][i].v] > dist[cur] + graph[cur][i].price){
				dist[graph[cur][i].v] = dist[cur] + graph[cur][i].price;
				q.push(graph[cur][i].v);
			}
		}

		done[cur] = 1;
	}

	for(i = 1; i <= n; i++)
		ans += dist[i];

	return ans;
}

int main(){
	int t, u = 0;
	scanf("%d", &t);
	while(u < t){
		int p, q, i, x, y, j;
		long int z, ans;
		scanf("%d %d", &p, &q);
		for(i = 0; i < q; i++){
			scanf("%d %d %ld", &x, &y, &z);
			temp.v = y;
			temp.price = z;
			graph1[x].push_back(temp);
			temp.v = x;
			graph2[y].push_back(temp);
		}

		ans = dijkstraAll(graph1, 1, p);
		ans += dijkstraAll(graph2, 1, p);

		printf("%ld\n", ans);
		++u;

		for(i = 1; i <= p; i++){
			graph1[i].resize(0);
			graph2[i].resize(0);
		}
	}
}