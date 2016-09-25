#include <bits/stdc++.h>
#define MAX 10010
#define INF 999999

using namespace std;

typedef pair<int, int> pii;

struct node {
	int v;
	int price;
};

vector<struct node> graph[MAX];
int price[MAX], done[MAX];

struct compare {
	bool operator()(const int& l, const int& r){
		return price[l] > price[r];
	}
};

int dijkstra(int s, int d, int n){
	priority_queue <int, vector <int>, compare> q;
	int i, cur, v, p;

	for(i = 0; i <= n; i++){
		done[i] = 0;
		price[i] = INF;
	}

	q.push(s);
	price[s] = 0;

	while(!q.empty()){
		cur = q.top();
		q.pop();

		if(cur == d)
			return price[cur];

		if(done[cur])
			continue;

		for(i = 0; i < graph[cur].size(); i++){
			v = graph[cur][i].v;
			p = graph[cur][i].price;

			if(!done[v] && price[v] > price[cur] + p){
				price[v] = price[cur] + p;
				q.push(v);
			}
		}

		done[cur] = 1;
	}

	return -1;
}

int main(){
	int t, p = 0, v, e, i;
	int x, y, z, a, b, ans;
	struct node temp;
	scanf("%d", &t);

	while(p < t){
		scanf("%d %d", &v, &e);
		for(i = 0; i < e; i++){
			scanf("%d %d %d", &x, &y, &z);
			temp.v = y;
			temp.price = z;
			graph[x].push_back(temp);
		}
		scanf("%d %d", &a, &b);
		ans = dijkstra(a, b, v);

		if(ans == -1)
			printf("NO\n");
		else
			printf("%d\n", ans);

		for(i = 0; i <= v; i++)
			graph[i].clear();

		++p;
	}

	return 0;
}