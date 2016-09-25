#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	int a, b, c, d, i;
	long long int ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		ans = 0;

		for(i = a; i <= b; i++){
			if(i < c)
				ans += (d - c + 1);

			else if(i < d)
				ans += (d - i);

			else
				break;
		}

		printf("%lld\n", ans);
	}
}