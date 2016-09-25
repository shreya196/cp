#include <stdio.h>

int main(){
	int n, i = 0;
	int x, rem, orig;
	scanf("%d", &n);
	while(i < n) {
		scanf("%d", &x);
		orig = x;
		rem = x%3;
		if(rem == 0)
			x = x - 3;
		else
			x = x - rem;
		while(x > 0){
			if((orig - x) % 5 == 0){
				printf("Case %d: %d\n",i+1 , x);
				break;
			}
			else {
				x = x - 3;
			}
		}
		if(x <= 0){
			printf("Case %d: %d\n", i+1, -1);
		}
		i++;
	}
	return 0;
}