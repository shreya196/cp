#include <bits/stdc++.h>
#define MAX 1100

using namespace std;

int arr[MAX][MAX];
vector<int> x1, x2;

int main(){
	int t;
	scanf("%d", &t);

	int n, m, i, x, y, temp, flag, j, l, k, found, p;
	while(t--){
		scanf("%d %d", &n, &m);

		for(k = 0; k < n; k++){
			for(j = 0; j < n; j++){
				arr[k][j] = 0;
			}
		}

		for(i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			arr[x - 1][y - 1] = 1;
			arr[y - 1][x - 1] = 1;
		}

		found = 0;
		for(k = 0; k < n; k++){
			x1.clear();x2.clear();

			for(p = 0; p < n; p++){

				i = (k + p)%n;
				flag = 0;
				l = x1.size();

				for(j = 0; j < l; j++){
					temp = x1[j];
					if(arr[i][temp] == 0){
						flag = 1;
						break;
					}
				}

				if(flag == 0){
					x1.push_back(i);
				}

				else {
					flag = 2;
					l = x2.size();
					for(j = 0; j < l; j++){
						temp = x2[j];
						if(arr[i][temp] == 0){
							flag = 3;
							break;
						}
					}

					if(flag == 3){
						break;
					}

					else {
						x2.push_back(i);
					}
				}
			}

			if(flag != 3) {
				found = 1;
				printf("YES\n");
				break;
			}
		}

		if(found == 0)
			printf("NO\n");
	}

	return 0;
}