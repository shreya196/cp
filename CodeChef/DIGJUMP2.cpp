#include <bits/stdc++.h>
#define INF 9999999
#define MAX 100010

using namespace std;

string str;
int done[MAX], dist[MAX], n;
vector<int> indices[10];

int shortest(int s){
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	done[s] = 1;

	int cur, i, temp, len, toPush;
	while(!q.empty()){
		cur = q.front();
		q.pop();

		if(cur == n)
			return dist[n];

		if(cur - 1 >= 0){
			if(!done[cur - 1]){
				q.push(cur - 1);
				dist[cur - 1] = dist[cur] + 1;
				done[cur - 1] = 1;
			}
		}

		if(cur + 1 <= n){
			if(!done[cur + 1]){
				q.push(cur + 1);
				dist[cur + 1] = dist[cur] + 1;
				done[cur + 1] = 1;
			}
		}

		temp = str[cur] - '0';
		len = indices[temp].size();
		for(i = 0; i < len; i++){
			toPush = indices[temp][i];
			if(!done[toPush]){
				q.push(toPush);
				dist[toPush] = dist[cur] + 1;
				done[toPush] = 1;
			}
		}
		indices[temp].clear();
	}
}

int main(){
	cin >> str;

	n = str.length() - 1;

	for(int i = 0; i <= n; i++){
		indices[str[i] - '0'].push_back(i);
	}

	cout << shortest(0) << "\n";
}