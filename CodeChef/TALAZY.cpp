#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);

	long long int n, b, m, s;
	long long int ans;
	while(t--){
		scanf("%lld %lld %lld", &n, &b, &m);

		ans = 0;
		while(n > 0){
			if(n%2 == 0)
				s = n/2;
			else
				s = (n+1)/2;

			ans += (s*m);

			n -= s;

			if(n > 0){
				m = 2*m;
				ans += b;
			}
		}

		printf("%lld\n", ans);
	}
}