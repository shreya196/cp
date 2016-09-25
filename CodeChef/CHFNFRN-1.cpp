#include <bits/stdc++.h>
#define MAX 1100

using namespace std;

int arr[MAX][MAX], frnd[MAX];
vector<int> x1, x2;

struct compare{
	bool operator()(int &l, int &r){
		return frnd[l] > frnd[r];
	}
};

int main(){
	int t;
	scanf("%d", &t);

	int n, m, i, x, y, j, cur, flag;
	int gr1, gr2;
	while(t--){
		scanf("%d %d", &n, &m);

		for(i = 0; i < n; i++){
			frnd[i] = 0;
			for(j = 0; j < n; j++){
				arr[i][j] = 0;
			}
		}

		for(i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			arr[x - 1][y - 1] = 1;
			arr[y - 1][x - 1] = 1;
			frnd[x - 1]++;
			frnd[y - 1]++;
		}

		priority_queue<int, vector<int>, compare> q;
		for(i = 0; i < n; i++)
			q.push(i);

		gr1 = q.top();
		q.pop();

		gr2 = -1;

		while(!q.empty()){
			flag = 0;
			cur = q.top();
			q.pop();
			cout << cur << "\n";

			for(i = 0; i < n; i++){
				if(arr[gr1][i] == 1 && arr[cur][i] == 0){
					flag = 1;
					break;
				}
			}

			if(flag == 1){
				if(gr2 != -1){
					for(i = 0; i < n; i++){
						if(arr[gr2][i] == 1 && arr[cur][i] == 0){
							flag = 2;
							break;
						}
					}

					if(flag == 2){
						printf("NO\n");
						break;
					}
				}

				else
					gr2 = cur;
			}

		}

		if(flag != 2)
			printf("YES\n");
	}

	return 0;
}