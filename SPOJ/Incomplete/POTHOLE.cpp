#include <bits/stdc++.h>
#define MAX 210

using namespace std;

int graph[MAX][MAX];

typedef pair<int, int> pii;

int bfs(int s, int n){
	queue <pii> q;
	int done[MAX], first, second, i;
	pii cur;

	for(i = 1; i <= n; i++)
		done[i] = 0;

	q.push(make_pair(s, 1));

	while(!q.empty()){
		cur = q.front();
		first = cur.first;
		second = cur.second;
		q.pop();

		if(done[first])
			continue;

		if(first == n){
			graph[second][first] = 0;
			return 1;
		}

		for(i = 1; i <= n; i++){
			if(!done[i] && graph[first][i]){
				q.push(make_pair(i, first));
			}
		}

		done[first] = 1;
	}
	return 0;
}

int main(){
	int t, p = 0, n, i, x, j, temp, count, k;
	scanf("%d", &t);

	while(p < t){
		scanf("%d", &n);
		count = 0;

		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				graph[i][j] = 0;
			}
		}

		for(i = 1; i <= n - 1; i++){
			scanf("%d", &x);
			for(j = 0; j < x; j++){
				scanf("%d", &temp);
				graph[i][temp] = 1;
			}
		}

		for(i = 1; i <= n; i++){
			if(graph[1][i] && i > 1){
				if(bfs(i, n))
					++count;
			}
		}
		printf("%d\n",  count);
		p++;
	}

	return 0;
}