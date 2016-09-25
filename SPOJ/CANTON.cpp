#include <bits/stdc++.h>
#define MAX 10000000

typedef long long int lli;

using namespace std;

int main(){
	lli sum[5000], x, ans;
	sum[0] = 0;
	int n = 1, j;
	while(sum[n-1] < MAX){
		sum[n] = sum[n - 1] + n;
		n++;
	}

	int t, i = 0;
	scanf("%d", &t);
	while(i < t){
		scanf("%lld", &x);
		j = 1;

		while(sum[j] < x)
			j++;

		ans = x - (sum[j - 1] + 1);
		if(j % 2 == 0){
			printf("TERM %lld IS %lld/%lld\n",x, 1 + ans, j - ans);
		}

		else {
			printf("TERM %lld IS %lld/%lld\n", x, j - ans, 1 + ans);
		}
		
		i++;
	}
}