#include <bits/stdc++.h>

using namespace std;

int main(){
	while(1){
		long long int n1, n2, i, countInter, ans, j;
		map <long long int, long long int> no1;

		scanf("%lld", &n1);
		if(n1 == 0)
			break;

		long long int arr1[n1];

		for(i = 0; i < n1; i++){
			scanf("%lld", &arr1[i]);
			no1[arr1[i]] = 1;
		}

		scanf("%lld", &n2);

		long long int sums[n2], intersections[n2], arr2[n2];

		countInter = 0;
		for(i = 0; i < n2; i++){
			scanf("%lld", &arr2[i]);

			if(no1.find(arr2[i]) != no1.end()){
				intersections[countInter++] = arr2[i];
			}
		}

		intersections[countInter] = -99999999;

		i = 0, j = 0, countInter = 0, ans = 0;
		long long int sum1 = 0, sum2 = 0;

		while(1){
			sum1 = 0;
			while(i < n1){
				sum1 += (arr1[i]);
				if(arr1[i] == intersections[countInter]){
					++i;
					break;
				}
				++i;
			}

			sum2 = 0;
			while(j < n2){
				sum2 += arr2[j];
				if(arr2[j] == intersections[countInter]){
					++j;
					break;
				}
				++j;
			}

			if(sum1 > sum2)
				ans += sum1;

			else
				ans += sum2;

			if(i >= n1 && j >= n2)
				break;

			++countInter;
		}
		cout << ans << "\n";
	}


	return 0;
}