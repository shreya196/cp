#include <bits/stdc++.h>
#define MAX 101
#define INF 999999

using namespace std;

typedef pair<int, int> pii;

int graph[MAX][MAX];

struct compare {
	bool operator()(const pii& l, const pii& r){
		return l.second > r.second;
	}
};

int dijkstra(int s, int d, int max){
	priority_queue <pii, vector<pii>, compare> q;
	int dist[MAX], done[MAX], i;
	pii cur;

	for(i = 1; i <= max; i++){
		dist[i] = INF;
		done[i] = 0;
	}

	q.push(make_pair(s, 0));
	dist[s] = 0;

	while(!q.empty()){
		cur = q.top();
		q.pop();

		if(cur.first == d)
			return dist[cur.first];

		if(done[cur.first])
			continue;

		for(i = 1; i <= max; i++){
			if(graph[cur.first][i] && !done[i] && (dist[i] > dist[cur.first] + graph[cur.first][i])){
				dist[i] = dist[cur.first] + graph[cur.first][i];
				q.push(make_pair(i, dist[i]));
			}
		}

		done[cur.first] = 1;
	}

	return INF;
}

int main(){
	int n, e, t, m, i;
	int x, y, z, temp, count = 0;
	scanf("%d %d %d %d", &n, &e, &t, &m);
	i = 0;
	while(i < m){
		scanf("%d %d %d", &x, &y, &z);
		graph[x][y] = z;
		i++;
	}

	for(i = 1; i <= n; i++){
		temp = dijkstra(i, e, n);
		if(temp <= t)
			count++;
	}

	printf("%d\n", count);
}