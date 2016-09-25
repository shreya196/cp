#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

vector <int> graph[MAX];
int done[MAX];

int check(int r, int n){
	stack <int> q;
	int cur, i;

	for(i = 1; i <= n; i++){
		done[i] = 0;
	}

	q.push(r);
	done[r] = 1;

	while(!q.empty()){
		cur = q.top();
		q.pop();

		for(i = 0; i < graph[cur].size(); i++){
			if(!done[graph[cur][i]]){
				q.push(graph[cur][i]);
				done[graph[cur][i]] = 1;
			}
		}
	}

	for(i = 1; i <= n; i++){
		if(!done[i])
			return 0;
	}

	return 1;
}

int main(){
	int n, m, i, u, v, ans, j;
	scanf("%d %d", &n, &m);

	for(i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if(m != n - 1){
		printf("NO\n");
		return 0;
	}

	ans = check(1, n);
	
	if(ans == 0){
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}

	for(i = 1; i <= n; i++)
		graph[i].clear();

	return 0;
}