#include <bits/stdc++.h>
#define MAX 100100
#define INF 999999999

using namespace std;

int arr[MAX];

int main(){
	int t, n, i, diff[3], min, j, k, flag = 0, pos = 1, prevMin;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		if(n == 2){
			if(arr[0] < arr[1])
				printf("%d\n", arr[0]);
			else
				printf("%d\n", arr[1]);
			continue;
		}

		else if(n == 3){
			if(arr[0] < arr[1]){
				if(arr[0] < arr[2])
					printf("%d\n", arr[0]);
				else
					printf("%d\n", arr[2]);
			}

			else {
				if(arr[1] < arr[2])
					printf("%d\n", arr[1]);
				else
					printf("%d\n", arr[2]);
			}

			continue;
		}

		else {
			diff[0] = arr[1] - arr[0];
			diff[1] = arr[2] - arr[1];
			diff[2] = arr[3] - arr[2];

			prevMin = INF;
			pos = 0;
			for(k = 0; k < 2; k++){
				flag = 0;
				min = INF;

				for(i = 1; i < n; i++){
					if(arr[i] - arr[i - 1] != diff[k]){
						if(i == n-1)
							j = i;

						else{
							if(arr[i + 1] - arr[i] != diff[k]){
								j = i;
							}

							else{
								j = i - 1;
							}
						}

						if(arr[j] < min)
							min = arr[j];

						if(flag == 0){
							flag = 1;
						}

						else {
							++pos;
							break;
						}
					}
				}

				if(i == n)
					prevMin = min;
			}

		}

		if(pos == 3)
			printf("-1\n");
		else if(prevMin == INF){
			if(arr[0] < arr[n-1])
				printf("%d\n", arr[0]);
			else
				printf("%d\n", arr[n-1]);
		}
		else
			printf("%d\n", prevMin);
	}

	return 0;
}