#include <bits/stdc++.h>
#define INF 999999999

using namespace std;
long long int ans;

void merge(int arr[], int start, int mid, int end){
	int arr1[mid - start + 2], arr2[end - mid + 1], i, j;
	for(i = start, j = 0; i <= mid; i++, j++)
		arr1[j] = arr[i];
	arr1[j] = INF;

	for(i = mid + 1, j = 0; i <= end; i++, j++)
		arr2[j] = arr[i];
	arr2[j] = INF;

	int count1 = 0, count2 = 0;
	for(i = start; i <= end; i++){
		if(arr1[count1] < arr2[count2]){
			arr[i] = arr1[count1++];
		}

		else{
			arr[i] = arr2[count2++];
			ans += ((mid - start + 1) - count1);
		}
	}
}

void mergeSort(int arr[], int p, int q){
	int r;
	if(p < q){
		r = (p + q)/2;
		mergeSort(arr, p, r);
		mergeSort(arr, r + 1, q);
		merge(arr, p, r, q);
	}
}

int main(){
	int t, p = 0;
	scanf("%d", &t);

	int n;
	while(p < t){
		scanf("%d", &n);
		int arr[n], i;

		for(i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}

		ans = 0;
		mergeSort(arr, 0, n - 1);
		printf("%lld\n", ans);
		++p;
	}

	return 0;
}