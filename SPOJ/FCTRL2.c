#include <stdio.h>

int main(){
	int arr[160], arrLen = 0;
	int x, i, j, carry, temp, t, p = 0;
	scanf("%d", &t);

	while(p < t){
		i = 2, arrLen = 0;
		arr[0] = 1;
		++arrLen;

		scanf("%d", &x);
		
		while(i <= x){
			j = 0, carry = 0;

			while(j < arrLen){
				temp = arr[j]*i + carry;
				arr[j] = temp%10;
				carry = temp/10;
				++j;
			}

			while(carry > 0){
				arr[j++] = carry%10;
				carry = carry/10;
				++arrLen;
			}

			++i;
		}

		j = arrLen - 1;
		while(j >= 0)
			printf("%d", arr[j--]);
		printf("\n");
		++p;
	}
	return 0;
}