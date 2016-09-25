#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int t, n, len, j, ans, i, len2, count;
	char p;
	int flag = 0;
	while(scanf("%lld",&n)!=EOF){
		flag++;
		char arr[n];
		char arr2[5000000];
		scanf("%s", arr);
		len = strlen(arr);

		ans = 0, j = 0, i = 0;
		scanf("%s", arr2);
		len2 = strlen(arr2);

		count = 0, ans = -1;
		while(i < len2){
			p = arr2[i];
			if(p == arr[j]){
				if(j == 0)
					ans = i;
				j++;
				if(j == len){
					printf("%lld\n", ans);
					j = 0;
					i = ans;
					count++;
				}
			}
			else {
				if(j != 0)
					i = ans;
				j = 0;
			}
			i++;
		}
		printf("\n");
		if(count == 0)
			printf("\n");
	}
}