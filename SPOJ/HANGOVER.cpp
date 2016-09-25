#include <bits/stdc++.h>

int main(){
	float x, sum;
	int count;
	while(1){
		scanf("%f", &x);
		if(x == 0)
			break;

		sum = 0;
		count = 1;
		while(sum < x){
			++count;
			sum += (1/(float)count);
		}

		printf("%d\n", count - 1);
	}
}