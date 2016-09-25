#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, i, x, y, total, j;
	scanf("%d", &t);

	while(t--){
		total = 0;
		scanf("%d", &n);
		vector<int> arr[n];
		int pointers[n]; 
		stack<int> q;

		for(i = 0; i < n; i++){

			pointers[i] = 0;

			scanf("%d", &x);
			total += x;
			for(j = 0; j < x; j++){
				scanf("%d", &y);
				arr[i].push_back(y);
			}
		}

		for(i = 0; i < total; i++){
			scanf("%d", &x);
			q.push(x);
		}

		while(!q.empty()){
			x = q.top();
			q.pop();

			for(i = 0; i < n; i++){
				if(pointers[i] <= arr[i].size()){
					if(arr[i][pointers[i]] == x){
						++pointers[i];
						break;
					}
				}
			}

		}

		int flag = 0;
		for(i = 0; i < n; i++){
			if(pointers[i] < arr[i].size()){
				flag = 1;
				break;
			}
		}

		if(flag == 0)
			printf("Yes\n");

		else
			printf("No\n");
	}
}