#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, double> pif;

vector<pii> arr[MAX];
int done[MAX];
double dist[MAX];

struct cmp {
	bool operator()(const pif &l, const pif &r){
		return l.second < r.second;
	}
};

double find(int s, int d){
	priority_queue<pif, vector<pif>, cmp> q;

	dist[s] = 1;
	q.push(make_pair(s, 1.0));

	pif curNode;
	int cur, i, temp;
	double curDist, tempDist;

	while(!q.empty()){

		curNode = q.top();
		q.pop();

		cur = curNode.first;
		curDist = curNode.second;

		if(cur == d){
			return curNode.second;
		}

		if(done[cur])
			continue;

		done[cur] = 1;

		for(i = 0; i < arr[cur].size(); i++){
			temp = arr[cur][i].first;
			tempDist = (double)(arr[cur][i].second);

			if(done[temp] != 1 && dist[temp] < curDist * tempDist/100.0){
				dist[temp] = curDist * tempDist/100.0;
				q.push(make_pair(temp, dist[temp]));
			}
		}
	}
}

int main(){
	int n, m, x, y, z, i;

	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;
		scanf("%d", &m);

		for(i = 1; i <= n; i++){
			arr[i].clear();
			done[i] = 0;
			dist[i] = -1;
		}

		for(i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			arr[x].push_back(make_pair(y, z));
			arr[y].push_back(make_pair(x, z));
		}

		printf("%lf percent\n", find(1, n)*100);
	}
}