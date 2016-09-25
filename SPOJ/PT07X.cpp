#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

vector<int> graph[MAX];
vector<int> r, g;
int done[MAX], color[MAX];

void find(int s, int n){
	queue<int> q;
	
	q.push(s);
	done[s] = 1;
	color[s] = 1;

	int cur, i, setColor, temp;

	while(!q.empty()){
		cur = q.front();
		q.pop(); 

		if(color[cur] == 1){
			r.push_back(cur);
			setColor = 2;
		}

		else{
			g.push_back(cur);
			setColor = 1;
		}

		for(i = 0; i < graph[cur].size(); i++){
			temp = graph[cur][i];
			if(done[temp] != 1){
				q.push(temp);
				done[temp] = 1;
				color[temp] = setColor;
			}
		}
	}

}

int main(){
	int n, i, x, y;
	scanf("%d", &n);

	for(i = 1; i <= (n-1); i++){
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	find(1, n);
	
	if(r.size() < g.size()){
		printf("%lld\n", r.size());
	}

	else {
		printf("%lld\n", g.size());
	}
}