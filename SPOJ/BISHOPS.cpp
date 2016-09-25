#include <bits/stdc++.h>
#define MAX 110

int subtract(char arr[], int len){
	int i = 0;
	while(arr[i] == '0' && i < len - 1){
		arr[i] = '9';
		i++;
	}

	arr[i] = arr[i] - 1;

	if(i == len - 1 && arr[i] == '0')
		return len - 1;

	else
		return len;
}

int multiply(char arr[], int len, int p){
	int i = 0, carry = 0, temp;
	while(i < len){
		temp = (arr[i] - '0')*p + carry;
		if(temp > 9){
			arr[i] = temp%10 + '0';
			carry = temp/10;
		}
		else {
			arr[i] = temp + '0';
			carry = 0;
		}
		i++;
	}

	if(carry != 0){
		arr[i] = carry + '0';
		len += 1;
	}

	return len;
}

int main(){
	char num[MAX], num2[MAX];
	int len, i, j;
	while(scanf("%s", num) != EOF){
		len = strlen(num);
		if(len == 1 && num[0] == '1'){
			printf("1\n");
		}
		else if(len == 1 && num[0] == '0'){
			printf("0\n");
		}
		else {
			for(i = len - 1, j = 0; i >= 0; i--, j++)
				num2[j] = num[i];

			int n = subtract(num2, len);
			
			n = multiply(num2, n, 2);

			for(i = n - 1; i >= 0; i--)
				printf("%c", num2[i]);
			printf("\n");
		}
	}
}