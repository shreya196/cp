#include <bits/stdc++.h>
#define MAX 185
#define INF 999999

using namespace std;

typedef pair<int, int> pii;
int dist[MAX][MAX];

int bfs(int sx, int sy, int x, int y){
	queue <int> q;
	pii temp, cur;
	int xi, yi;

	q.push(sx);
	q.push(sy);

	while(!q.empty()){
		xi = q.front();
		q.pop();
		yi = q.front();
		q.pop();

		if(xi + 1 < x){
			if(dist[xi][yi] + 1 < dist[xi + 1][yi]){
				q.push(xi+1);
				q.push(yi);
				dist[xi+1][yi] = dist[xi][yi] + 1;
			}
		}

		if(xi - 1 >= 0){
			if(dist[xi][yi] + 1 < dist[xi - 1][yi]){
				q.push(xi-1);
				q.push(yi);
				dist[xi-1][yi] = dist[xi][yi] + 1;
			}
		}

		if(yi + 1 < y){
			if(dist[xi][yi] + 1 < dist[xi][yi + 1]){
				q.push(xi);
				q.push(yi+1);
				dist[xi][yi+1] = dist[xi][yi] + 1;
			}
		}


		if(yi - 1 >= 0){
			if(dist[xi][yi] + 1 < dist[xi][yi - 1]){
				q.push(xi);
				q.push(yi-1);
				dist[xi][yi-1] = dist[xi][yi] + 1;
			}
		}
	}
}

int main(){
	long long int t, p = 0;
	int x, y, i, j, count;
	char ch;
	cin >> t;
	int arr[MAX*MAX], arr2[MAX*MAX];
	
	while(p < t){
		cin >> x >> y;
		for(i = 0, count = 0; i < x; i++){
			for(j = 0; j < y; j++){
				cin >> ch;

				if(ch == '1'){
					arr[count] = i;
					arr2[count] = j;
					dist[i][j] = 0;
					count += 1;
				}

				else
					dist[i][j] = INF;
			}
		}

		for(i = 0; i < count; i++)
			bfs(arr[i], arr2[i], x, y);

		for(i = 0; i < x; i++){
			for(j = 0; j < y; j++){
				cout << dist[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		p++;
	}
}