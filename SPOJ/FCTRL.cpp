#include <bits/stdc++.h>

long long int findtrailingZeros(long long int x){
	long long int p = 5, ans = 0;
	while(p <= x){
		ans += (x / p);
		p *= 5;
	}
	return ans;
}

int main(){
	int t, i = 0;
	long long int x;
	scanf("%d", &t);
	while(i < t){
		scanf("%lld", &x);
		printf("%lld\n", findtrailingZeros(x));
		i++;
	}
}