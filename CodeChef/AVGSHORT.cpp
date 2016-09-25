#include <bits/stdc++.h>
#define MAX 520
#define INF 999999

using namespace std;

typedef pair<int, int> pii;

struct compare {
	bool operator()(const pii &l, const pii &r){
		return l.second > r.second;
	}
};

struct node {
	int v;
	int d;
} temp;

vector<struct node> graph1[MAX], graph2[MAX];
int dist1[MAX], dist2[MAX];
int no1[MAX], no2[MAX];
int done1[MAX], done2[MAX];

void dij1(int s, int d, int n){
	priority_queue<pii, vector<pii>, compare> q;

	dist1[s] = 0;
	no1[s] = 0;
	q.push(make_pair(s, 0));

	pii curNode;
	int cur, curd, i;
	int temp1, temp2;
	while(!q.empty()){
		curNode = q.top();
		q.pop();

		cur = curNode.first;
		curd = curNode.second;

		if(done1[cur])
			continue;

		done1[cur] = 1;

		for(i = 0; i < graph1[cur].size(); i++){
			temp = graph1[cur][i];
			temp1 = temp.v;
			temp2 = temp.d;
			if(!done1[temp1] && dist1[temp1] > dist1[cur] + temp2){
				dist1[temp1] = dist1[cur] + temp2;
				no1[temp1] = no1[cur] + 1;
				q.push(make_pair(temp1, dist1[temp1]));
			}
		}
	}
}

void dij2(int s, int d, int n){
	priority_queue<pii, vector<pii>, compare> q;

	dist2[s] = 0;
	no2[s] = 0;
	q.push(make_pair(s, 0));

	pii curNode;
	int cur, curd, i;
	int temp1, temp2;
	while(!q.empty()){
		curNode = q.top();
		q.pop();

		cur = curNode.first;
		curd = curNode.second;

		if(done2[cur])
			continue;

		done2[cur] = 1;

		for(i = 0; i < graph2[cur].size(); i++){
			temp = graph2[cur][i];
			temp1 = temp.v;
			temp2 = temp.d;
			if(!done2[temp1] && dist2[temp1] > dist2[cur] + temp2){
				dist2[temp1] = dist2[cur] + temp2;
				no2[temp1] = no2[cur] + 1;
				q.push(make_pair(temp1, dist2[temp1]));
			}
		}
	}
}

int cycle[MAX];
int done3[MAX];
int checkCycle(int s){
	if(cycle[s] == 1)
		return 1;

	cycle[s] = 1;

	int temp, i;
	for(i = 0; i < graph1[s].size(); i++){
		if(!done3[i]){
			temp = checkCycle(graph1[s][i].v);
			if(temp == 1)
				return temp;
		}
	}
	
	cycle[s] = 0;
	done3[s] = 1;
	return 0;
}

int main(){
	int t;
	scanf("%d", &t);

	int n, m, i, x, y, z, s, d;
	while(t--){
		scanf("%d %d", &n, &m);

		for(i = 1; i <= n; i++){
			dist1[i] = INF;
			dist2[i] = INF;
			done1[i] = 0;
			done2[i] = 0;
			no1[i] = 0;
			no2[i] = 0;
			graph1[i].clear();
			graph2[i].clear();
			done3[i] = 0;
			cycle[i] = 0;
		}

		for(i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			temp.v = y;
			temp.d = z;
			graph1[x].push_back(temp);
			temp.v = x;
			temp.d = z;
			graph2[y].push_back(temp);
		}

		scanf("%d %d", &s, &d);
		int pqr = checkCycle(1);

		if(pqr == 1){
			cout << "Cycle found\n";
		}

		else {
			dij1(s, d, n);
			dij2(d, s, n);

			if(dist1[d] == INF){
				printf("-1\n");
			}

			else {
				float ans = -1, some;
				for(i = 1; i <= n; i++){
					some = (float)(dist1[i] + dist2[i])/(float)(no1[i] + no2[i]);
					if(some < ans || ans < 0)
						ans = some;
				}
				printf("%f\n", ans);
			}	
		}
	}

	return 0;
}