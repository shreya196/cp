#include <bits/stdc++.h>
#define MAX 100010
#define INF 999999

using namespace std;

vector<int> graph[MAX];
int nextNode;

int bfs(int s, int n){
	queue<int> q;
	int dist[n], i;

	memset(dist, -1, sizeof(dist));
	
	q.push(s);
	dist[s] = 0;

	int cur, temp, max = 0, maxNode = -1;

	while(!q.empty()){
		cur = q.front();
		q.pop();

		if(dist[cur] > max){
			max = dist[cur];
			maxNode = cur;
		}

		for(i = 0; i < graph[cur].size(); i++){
			temp = graph[cur][i];
			if(dist[temp] == -1){
				q.push(temp);
				dist[temp] = dist[cur] + 1;
			}
 		}
	}

	nextNode = maxNode;
	return max;
}

int main(){
	int c, n, i, x, y, ans, temp;
	scanf("%d", &c);

	while(c--){
		scanf("%d", &n);

		for(i = 1; i <= n-1; i++){
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		bfs(0, n);
		ans = bfs(nextNode, n);

		if(ans > 1){
			if(ans%2 == 0)
				ans = ans/2;
			else
				ans = ans/2 + 1;
		}

		printf("%d\n", ans);

		for(i = 0; i < n; i++)
			graph[i].clear();
	}

	return 0;
}