#include <bits/stdc++.h>

char graph[110][110], done[110][110];

char str[10] = {'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
int len = 10;

int moveX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int moveY[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int nMoves = 8;

int dfs(int r, int c, int count, int maxX, int maxY){
	done[r][c] = 1;
	int i, j, x, y, ans;

	if(count == len - 1){
		return 1;
	}

	for(i = 0; i < nMoves; i++){
		x = r + moveX[i];
		y = c + moveY[i];

		if(x < 0 || y < 0 || x >= maxX || y >= maxY ){}
		else{
			if(graph[x][y] == str[count + 1] && !done[x][y]){
				ans = dfs(x, y, count + 1, maxX, maxY);
				if(ans == 1)
					return 1;
			}
		}
	}

	done[r][c] = 0;
	return 0;
}

int main(){
	int t, p = 0;
	int r, c, i, j, ans, flag;
	int x, y;
	scanf("%d", &t);
	while(p < t){
		scanf("%d %d", &r, &c);

		i = 0;
		while(i < r){
			scanf("%s", graph[i]);
			i++;
		}

		i = 0;
		j = 0;
		flag = 0;
		while(i < r){
			j = 0;
			while(j < c){
				if(graph[i][j] == 'A'){
					for(x = 0; x < r; x++){
						for(y = 0; y < c; y++){
							done[x][y] = 0;
						}
					}

					ans = dfs(i, j, 0, r, c);

					if(ans == 1){
						printf("YES\n");
						flag = 1;
						break;
					}
				}
				j++;
			}
			if(flag == 1)
				break;

			i++;
		}

		if(flag == 0)
			printf("NO\n");

		p++;
	}
}