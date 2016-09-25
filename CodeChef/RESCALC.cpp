#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, x, j, y, i, temp, max, tie;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		map<int, int> arr[n];
		int score[n] = {0};

		for(i = 0; i < n; i++){
			scanf("%d", &x);
			score[i] += x;

			for(j = 0; j < x; j++){
				scanf("%d", &y);
				if(arr[i].find(y) == arr[i].end()){
					arr[i][y] = 1;
				}

				else
					arr[i][y] += 1;
			}
		}

		max = -1;
		tie = 0;
		for(j = 0; j < n; j++){
			while(1){
				temp = 0;
				for(i = 1; i <= 6; i++){
					if(arr[j].find(i) != arr[i].end()){
						if(arr[j][i] > 0){
							arr[j][i] -= 1;
							temp += 1;
						}
					}
				}

				if(temp < 4)
					break;

				if(temp == 4)
					score[j] += 1;

				else if(temp == 5)
					score[j] += 2;

				else if(temp == 6)
					score[j] += 4;
			}

			if(max == -1 || score[j] >= score[max]){
				if(max == -1){
					max = j;
				}

				else if(score[j] == score[max]){
					tie = 1;
					max = j;
				}

				else {
					max = j;
					tie = 0;
				}
			}		
		}

		if(tie == 1)
			printf("tie\n");

		else{
			if(max + 1 == 1)
				printf("chef\n");
			else
				printf("%d\n", max + 1);
		}
	}

	return 0;
}