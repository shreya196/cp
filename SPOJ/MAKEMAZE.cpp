#include <bits/stdc++.h>

using namespace std;

char graph[1000][1000];
int x, y, visited[1000][1000];

void bfs(int x1, int y1, int x2, int y2){
	queue <int> q1;
	queue <int> q2;
	int i, j, tempX, tempY;

	for(i = 0; i < x; i++)
		for(j = 0; j < y; j++)
			visited[i][j] = 0;

	q1.push(x1);
	q2.push(y1);
	visited[x1][y1] = 1;

	while(!q1.empty()){
		tempX = q1.front();
		tempY = q2.front();
		q1.pop();
		q2.pop();

		if(tempX == x2 && tempY == y2){
			printf("valid\n");
			return;
		}

		if((tempX + 1) < x && graph[tempX + 1][tempY] == '.' && !visited[tempX + 1][tempY]){
			q1.push(tempX + 1);
			q2.push(tempY);
			visited[tempX + 1][tempY] = 1;
		}

		if((tempX - 1) >= 0 && graph[tempX - 1][tempY] == '.' && !visited[tempX - 1][tempY]){
			q1.push(tempX - 1);
			q2.push(tempY);
			visited[tempX - 1][tempY] = 1;
		}

		if((tempY + 1) < y && graph[tempX][tempY + 1] == '.' && !visited[tempX][tempY + 1]){
			q1.push(tempX);
			q2.push(tempY + 1);
			visited[tempX][tempY + 1] = 1;
		}

		if((tempY - 1) >= 0 && graph[tempX][tempY - 1] == '.' && !visited[tempX][tempY - 1]){
			q1.push(tempX);
			q2.push(tempY - 1);
			visited[tempX][tempY - 1] = 1;
		}
	}

	printf("invalid\n");
}

int main(){
	int t, i = 0;
	int p, q, count, x1, y1, x2, y2;
	scanf("%d", &t);
	while(i < t){
		count = 0;
		scanf("%d %d", &x, &y);
		for(p = 0; p < x; p++){
			for(q = 0; q < y; q++){
				cin >> graph[p][q];
				if((graph[p][q] == '.') && (p == 0 || p == (x - 1) || q == 0 || q == (y - 1))){
					count++;
					if(count == 1){
						x1 = p;
						y1 = q;
					}
					else {
						x2 = p;
						y2 = q;
					}
				}
			}
		}

		if(count != 2)
			printf("invalid\n");
		else
			bfs(x1, y1, x2, y2);
		i++;
	}
}