#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int checkAll9(char num[], long int n){
	long int i = 0;
	while(i < n){
		if(num[i] != '9')
			return 0;
		i++;
	}
	return 1;
}

int cmp(char num1[], char num2[], long int len){
	long int i = 0;
	while(i < len){
		if(num1[i] > num2[i])
			return -1;
		else if(num1[i] < num2[i])
			return 1;
		i++;
	}
	return 0;
}

void addAndMirror(char num1[], char num2[], long int len){
	long int mid;
	mid = len/2;
	int carry = 0;

	do {
		if(!carry)
			num2[mid] += 1;
		else
			num2[mid] += carry;

		if(num2[mid] > '9'){
			num2[mid] = '0';
			carry = 1;
		}
		else
			carry = 0;

		mid += 1;
	} while(carry);

	long int i, j;
	if(len % 2 == 0){
		i = len/2 - 1;
		j = len/2;
	}

	else {
		i = len/2 - 1;
		j = len/2 + 1;
	}

	while(i >= 0){
		if(num2[i] != num2[j]){
			num2[i] = num2[j];
		}
		--i;
		++j;
	}
}

void genPal(char num1[], char num2[], long int len){
	long int i, j;
	if(len % 2 == 0){
		i = len/2 - 1;
		j = len/2;
	}

	else {
		i = len/2 - 1;
		j = len/2 + 1;
	}

	while(i >= 0){
		if(num2[i] != num2[j])
			num2[j] = num2[i];
		--i;
		++j;
	}

	int cmpRes = cmp(num1, num2, len);

	if(cmpRes == 1){
		return;
	}

	else {
		addAndMirror(num1, num2, len);
	}
}

int main(){
	int t, p = 0;
	scanf("%d", &t);
	char num1[MAX], num2[MAX];
	long int len, i;
	while(p < t){
		scanf("%s", num1);
		len = strlen(num1);
		if(checkAll9(num1, len)){
			printf("1");
			for(i = 1; i < len; i++)
				printf("0");
			printf("1\n");
		}

		else {
			strcpy(num2, num1);
			genPal(num1, num2, len);
			printf("%s\n", num2);
		}
		p++;
	}
}