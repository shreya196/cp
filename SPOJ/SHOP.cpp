#include <bits/stdc++.h>
#define MAX 30
#define INF 99999

using namespace std;

typedef pair<int, int> pii;

char graph[MAX][MAX];
int done[MAX][MAX], dist[MAX][MAX];
int dir1[4] = {1, 0, -1, 0}, dir2[4] = {0, -1, 0, 1};

struct compare{
	bool operator()(const pii &l, const pii &r){
		return dist[l.first][l.second] > dist[r.first][r.second];
	}
};

int shortestPath(int sw, int sh, int dw, int dh, int w, int h){
	priority_queue<pii, vector<pii>, compare> q;

	int i, j;

	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			done[i][j] = 0;
			dist[i][j] = INF;
		}
	}

	pii cur;
	int curh, curw, temph, tempw;

	q.push(make_pair(sh, sw));
	dist[sh][sw] = 0;

	while(!q.empty()){
		cur = q.top();
		q.pop();

		curh = cur.first;
		curw = cur.second;

		if(curh == dh && curw == dw)
			break;

		if(done[curh][curw])
			continue;

		for(i = 0; i < 4; i++){
			temph = curh + dir2[i];
			tempw = curw + dir1[i];
			if((temph >= 0) && (temph < h)){
				if((tempw >= 0) && (tempw < w)){
					if(graph[temph][tempw] != 'X'){
						if(!done[temph][tempw] && dist[temph][tempw] > dist[curh][curw] + (graph[temph][tempw] - '0')){
							if(graph[temph][tempw] == 'S' || graph[temph][tempw] == 'D')
								dist[temph][tempw] = dist[curh][curw] + 0;
							else
								dist[temph][tempw] = dist[curh][curw] + (graph[temph][tempw] - '0');
							q.push(make_pair(temph, tempw));
						}
					}
				}
			}

		}
		done[curh][curw] = 1;
	}

	return dist[dh][dw];
}

int main(){
	int w, h, i, j;
	int dw, dh, sw, sh;
	while(1){
		scanf("%d %d", &w, &h);

		if(w == 0 && h == 0)
			break;

		for(i = 0; i < h; i++)
			scanf("%s", graph[i]);

		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				if(graph[i][j] == 'S'){
					sw = j;
					sh = i;
				}

				else if(graph[i][j] == 'D'){
					dw = j;
					dh = i;
				}
			}
		}

 		int ans = shortestPath(sw, sh, dw, dh, w, h);
		printf("%d\n", ans);
	}

	return 0;
}