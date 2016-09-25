#include <bits/stdc++.h>

using namespace std;

int main(){
	int n1, n2, i, j;
	scanf("%d %d", &n1, &n2);

	int arr1[n1][26] = {0}, arr2[n2][26] = {0}, count, k, len;
	long long int ans;

	char temp;
	char arr[1010];
	for(i = 0; i < n1; i++){
		scanf("%s", arr);

		len = strlen(arr);
		for(j = 0; j < len; j++){
			temp = arr[j];
			arr1[i][temp - 'A'] = 1;
		}
	}

	for(i = 0; i < n2; i++){
		scanf("%s", arr);

		len = strlen(arr);
		for(j = 0; j < len; j++){
			temp = arr[j];
			arr2[i][temp - 'A'] = 1;
		}
	}

	ans = 0;
	for(i = 0; i < n1; i++){
		for(j = 0; j < n2; j++){
			count = 0;
			for(k = 0; k < 26; k++){
				if(arr1[i][k] == 1 || arr2[j][k] == 1)
					++count;
				else
					break;
			}

			if(count == 26)
				++ans;
		}
	}

	printf("%lld\n", ans);
}