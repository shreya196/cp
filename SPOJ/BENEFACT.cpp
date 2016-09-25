#include <bits/stdc++.h>
#define MAX 50010

using namespace std;

struct node {
	int v;
	int dist;
};

vector <struct node> graph[MAX];
int firstStage;
int done[MAX];
long long int dist[MAX];


long long int find(int r, int n){
	stack <int> q;
	int i, sur, m, d, cur;
	long long int max = 0;

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
			m = graph[cur][i].v;
			d = graph[cur][i].dist;
			if(!done[m]){
				done[m] = 1;
				dist[m] = dist[cur] + d;
				q.push(m);
			}
		}
	}

	for(i = 1; i <= n; i++){
		if(dist[i] > max){
			max = dist[i];
			firstStage = i;
		}
	}

	return max;
}

int main(){
	int t, p = 0, i, n, x, y, z;
	scanf("%d", &t);
	struct node temp;
	long long int ans;

	while(p < t){
		scanf("%d", &n);

		for(i = 1; i <= (n - 1); i++){
			scanf("%d %d %d", &x, &y, &z);
			temp.v = y;
			temp.dist = z;
			graph[x].push_back(temp);
			temp.v = x;
			temp.dist = z;
			graph[y].push_back(temp);
		}

		find(1, n);
		ans = find(firstStage, n);

		printf("%lld\n", ans);
		++p;

		for(i = 1; i <= n; i++)
			graph[i].clear();
	}

	return 0;
}