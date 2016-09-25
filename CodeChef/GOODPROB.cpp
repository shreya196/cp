#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main(){
	int n, i, j, x;
	scanf("%d", &n);
	int arr[n], temp1, temp2, temp3;
	long long int ans;

	vector<int> maxs[n];
	ans = 0;

	for(i = 0; i < n; i++){
		scanf("%d", &x);
		arr[i] = x;
		for(j = 0; j < i; j++){
			if(maxs[j][i - j - 1] > x)
				maxs[j].push_back(maxs[j][i - j - 1]);

			else
				maxs[j].push_back(x);

			temp1 = arr[i];
			temp2 = arr[j];
			temp3 = temp1&temp2;

			if(temp3 == temp1 || temp3 == temp2){
				ans += maxs[j][i - j];
			}
		}

		maxs[j].push_back(x); 
	}

	printf("%lld\n", ans);
	return 0;
}