#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

vector<int> graph[MAX];
int done[MAX], dist[MAX];
int firstStage;

int find(int r, int n){
	stack <int> q;
	int i, cur, max = 0, adj;

	for(i = 1; i <= n; i++){
		done[i] = 0;
		dist[i] = 0;
	}

	q.push(r);
	done[r] = 1;
	dist[r] = 0;

	while(!q.empty()){
		cur = q.top();
		q.pop();

		for(i = 0; i < graph[cur].size(); i++){
			adj = graph[cur][i];
			if(!done[adj]){
				q.push(adj);
				dist[adj] = dist[cur] + 1;
				done[cur] = 1;
			}
		}
	}

	max = 0;
	for(i = 1; i <= n; i++){
		if(dist[i] > max){
			max = dist[i];
			firstStage = i;
		}
	}

	return max;
}

int main(){
	int x, i, p, q, ans = 0, temp;
	scanf("%d", &x);

	int arr[x+1];

	for(i = 1; i <= x ; i++)
		arr[i] = 0;

	for(i = 1; i <= x - 1; i++){
		scanf("%d %d", &p, &q);
		graph[p].push_back(q);
		arr[p] += 1;
		graph[q].push_back(p);
	}

	temp = find(i, x);
	ans = find(firstStage, x);

	printf("%d\n", ans);

	return 0;
}