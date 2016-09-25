#include <bits/stdc++.h>

using namespace std;

int changeRep(int x){
	char binary[50];
	int ans;

	int temp, i = 0;
	while(x > 0){
		temp = x%2;
		binary[i++] = temp + '0';
		x = x/2;
	}

	ans = 0;
	int len = i, pow2 = 1;

	for(i = len - 1; i >= 0; i--){
		ans += ((binary[i] - '0') * pow2);
		pow2 = pow2 * 2;
	}

	return ans;
}


int main(){
	int n, i = 0, x;
	scanf("%d", &n);

	while(i < n){
		scanf("%d", &x);
		if(x % 2 != 0)
			printf("%d\n", x);

		else
			printf("%d\n", changeRep(x));

		++i;
	}
}