#include <stdio.h>

int seive[100000];
int prime[100000];

int main(){
	int i, count = 0;
	long long int num, num2, j, k;
	int n;

	seive[0] = 1;
	seive[1] = 1;
	for(i = 2; i*i < 100000; i++)
		if(seive[i] == 0)
			for(j = i*2; j < 100000; j+=i)
				if(seive[j] == 0)
					seive[j] = 1;

	for(i = 2; i < 100000; i++)
		if(seive[i] == 0)
			prime[count++] = i;
		
	scanf("%d", &n);

	i = 0;
	while(i < n){
		scanf("%lld %lld", &num, &num2);

		for(j = num; j <= num2; j++){
			if(j < 100000){
				if(seive[j] == 0)
					printf("%lld\n", j);
			}

			else {
				for(k = 0; k < count; k++){
					if(j%prime[k] == 0)
						break;
				}
				if(k == count)
					printf("%lld\n", j);
			}
		}
		printf("\n");
		i++;
	}

	return 0;
}