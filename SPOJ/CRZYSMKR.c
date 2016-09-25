#include <stdio.h>

int main(){
	long long int n, x, i = 0, temp, rem, j = 0;
	scanf("%lld", &x);
	while(i < x){
		j = 0;
		scanf("%lld", &n);
		temp  = (8*(n%11))%11;
		while(1){
			rem = temp + (j%11);
			if(rem >= 11)
				rem = rem % 11;
			if(rem == 0){
				printf("%lld\n", j);
				break;
			}
			j += 1;
		}
		i++;
	}
	return 0;
}