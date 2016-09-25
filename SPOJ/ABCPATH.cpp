#include <bits/stdc++.h>
#define MAX 100

using namespace std;

char graph[MAX][MAX];
int done[MAX][MAX];
int moveX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int moveY[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int nMoves = 8;
char maxVal;

void dfs(int sx, int sy, int h, int w, char count){
	int i, x, y;
	for(i = 0; i < nMoves; i++){
		x = sx + moveX[i];
		y = sy + moveY[i];

		if(x >= 0 && x < h && y >= 0 && y < w){
			if(!done[x][y] && graph[x][y] == count){
				if(count > maxVal)
					maxVal = count;
				done[x][y] = 1;
				dfs(x, y, h, w, count + 1);
			}
		}
	}
}

int main(){
	int h, w, i, j, count = 1, m, n, flag;

	while(1){
		scanf("%d %d", &h, &w);
		if(h == 0 && w == 0)
			break;

		for(i = 0; i < h; i++){
			scanf("%s", graph[i]);
		}

		maxVal = 'A';
		flag = 0;

		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				if(graph[i][j] == 'A'){
					flag = 1;
					for(m = 0; m < h; m++){
						for(n = 0; n < w; n++){
							done[m][n] = 0;
						}
					}

					dfs(i, j, h, w, 'B');
				}
			}
		}

		if(flag == 0)
			printf("Case %d: 0\n", count);
		else
			printf("Case %d: %d\n", count, maxVal - 'A' + 1);

		++count;
	}
	
	return 0;
}