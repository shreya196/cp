#include <bits/stdc++.h>
#define MAX 110
#define INF 999999

using namespace std;

typedef pair<int, int> pii;

int blocks[MAX][MAX], sum[MAX][MAX], done[MAX][MAX];
int dir1[4] = {1, 0, -1, 0};
int dir2[4] = {0, -1, 0, 1};

struct compare{
	bool operator()(const pii &l, const pii &r){
		return sum[l.first][l.second] > sum[r.first][r.second];
	}
};

int find(int dx, int dy, int m, int n){
	priority_queue<pii, vector<pii>, compare> q;

	sum[1][1] = blocks[1][1];
	q.push(make_pair(1, 1));

	pii cur;
	int x, y, i, tempx, tempy;
	while(!q.empty()){
		cur = q.top();
		q.pop();
		x = cur.first;
		y = cur.second;

		if(x == dx && y == dy){
			return sum[x][y];
		}

		if(done[x][y])
			continue;

		for(i = 0; i < 4; i++){
			tempx = x + dir1[i];
			tempy = y + dir2[i];
			if(tempx > 0 && tempx <= m && tempy > 0 && tempy <= n){
				if(!done[tempx][tempy] && sum[tempx][tempy] > sum[x][y] + blocks[tempx][tempy]){
					sum[tempx][tempy] = sum[x][y] + blocks[tempx][tempy];
					q.push(make_pair(tempx, tempy));
				}
			}
		}

		done[x][y] = 1;
	}
}

int main(){
	int t, m, n, i, j;
	int dx, dy, req;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &n);
		for(i = 1; i <= m; i++){
			for(j = 1; j <= n; j++){
				scanf("%d", &blocks[i][j]);
				sum[i][j] = INF;
				done[i][j] = 0;
			}
		}

		scanf("%d %d %d", &dx, &dy, &req);
		int ans = find(dx, dy, m, n);

		if(ans > req)
			printf("NO\n");

		else 
			printf("YES\n%d\n", req - ans);
	}

	return 0;
}