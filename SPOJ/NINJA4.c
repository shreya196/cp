#include <stdio.h>

int main(){
	int x, i = 0;
	long long int num;
	long long int q;
	int r;
	scanf("%d", &x);
	while(i < x){
		scanf("%lld", &num);
		q = num / 4;
		r = num % 4;

		if(r == 1 || r == 2){
			printf("%lld ", (q*2 + 1));
		}
		else {
			if(r == 3){
				printf("%lld ", -((q+1)*2));
			}
			else
				printf("%lld ", -(q*2));
		}

		if(r == 1) {
			printf("%lld\n", -(q*2));
		}

		else if(r == 2){
			printf("%lld\n", ((q+1)*2));
		}

		else if(r == 3){
			printf("%lld\n", ((q+1)*2));
		}

		else {
			printf("%lld\n", -(q*2));
		}
		i++;
	}
	return 0;
}