#include <bits/stdc++.h>
#define MAX 1000
#define INF 99999999

using namespace std;

typedef pair <int, int> pii;

struct compare{
	bool operator()(pii &l, pii &r){
		return l.second > r.second;
	}
};

int graph[MAX][MAX], pred[MAX], dist[MAX];
int graph2[MAX][MAX], pred2[MAX], dist2[MAX];

int find(int s, int d, int n){
	priority_queue<pii, vector<pii>, compare> q;

	int i, done[n];

	for(i = 0; i < n; i++){
		pred[i] = -1;
		done[i] = 0;
		dist[i] = INF;
	}

	q.push(make_pair(s, 0));
	dist[s] = 0;
	pred[s] = -1;

	int cur, curDist, min = INF;

	while(!q.empty()){
		cur = q.top().first;
		curDist = q.top().second;
		q.pop();

		if(done[cur])
			continue;

		for(i = 0; i < n; i++){
			if(graph[cur][i] && !done[i] && dist[i] > dist[cur] + graph[cur][i]){
				dist[i] = dist[cur] + graph[cur][i];
				pred[i] = cur;
				q.push(make_pair(i, dist[i]));
			}
		}
		done[cur] = 1;
	}
	return dist[d];
}

void find2(int s, int d, int n){
	priority_queue<pii, vector<pii>, compare> q;

	int i, done2[n];

	for(i = 0; i < n; i++){
		pred2[i] = -1;
		done2[i] = 0;
		dist2[i] = INF;
	}

	q.push(make_pair(s, 0));
	dist2[s] = 0;
	pred2[s] = -1;

	int cur, curDist, min = INF;

	while(!q.empty()){
		cur = q.top().first;
		curDist = q.top().second;
		q.pop();

		if(done2[cur])
			continue;

		for(i = 0; i < n; i++){
			if(graph2[cur][i] && !done2[i] && dist2[i] > dist2[cur] + graph2[cur][i]){
				dist2[i] = dist2[cur] + graph2[cur][i];
				pred2[i] = cur;
				q.push(make_pair(i, dist2[i]));
			}
		}
		done2[cur] = 1;
	}
}



int main(){
	int n, m, s, d, i, x, y, z, min, temp, cur, j;

	while(1){
		scanf("%d %d", &n, &m);

		if(n == 0 && m == 0)
			break;

		scanf("%d %d", &s, &d);

		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				graph[i][j] = 0;
				graph2[i][j] = 0;
			}
		}

		for(i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			graph[x][y] = z;
			graph2[y][x] = z;
		}

		min = find(s, d, n);
		find2(d, s, n);

		for(i = 0; i < n; i++){
			if(dist[i] + dist2[i] == min){
				cur = i;
				while(pred[cur] != -1){
					graph[pred[cur]][cur] = 0;
					temp = cur;
					cur = pred[cur];
					pred[temp] = -1;
				}

				cur = i;
				while(pred2[cur] != -1){
					graph[cur][pred2[cur]] = 0;
					temp = cur;
					cur = pred2[cur];
					pred2[temp] = -1;
				}
			}
		}

		temp = find(s, d, n);

		if(temp == INF)
			temp = -1;

		printf("%d\n", temp);
	}
}