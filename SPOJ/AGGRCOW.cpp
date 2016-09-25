#include <bits/stdc++.h>

using namespace std;

long long int count(long long int arr[], int n, int c){
	int start = 1, end = arr[n -1], mid, i, count, temp, cur;
	long long int minD;

	while(start < end){
		mid = start + (end - start + 1)/2;
		minD = mid;

		cur = 0;
		count = 1;
		for(i = 1; i < n; i++){
			if(arr[i] - arr[cur] >= minD){
				cur = i;
				++count;
			}
		}

		if(count >= c) {
			start = mid;
		}

		else {
			end = mid - 1;
		}

	}

	return start;
}

int main(){
	int t, p = 0, n, c, i;
	scanf("%d", &t);

	while(p < t){
		scanf("%d %d", &n, &c);
		long long int dist[n];

		for(i = 0; i < n; i++){
			scanf("%lld", &dist[i]);
		}

		sort(dist, dist + n);
		cout << count(dist, n, c) << "\n";

		++p;
	}

	return 0;
}