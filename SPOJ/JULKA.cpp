#include <bits/stdc++.h>

using namespace std;

void sum(char num1[], char num2[]){
	int len1 = strlen(num1), len2 = strlen(num2);
	int i = 0, carry = 0, temp;
	while(i < len1){
		temp = (num1[i] - '0') + carry;

		if(i < len2)
			temp += (num2[i] - '0');

		num1[i] = temp%10 + '0';
		carry = temp/10;
		++i;
	}

	if(carry != 0){
		num1[i] = carry + '0';
		++i;
	}

	num1[i] = '\0';
}

void diff(char num1[], char num2[]){
	int len1 = strlen(num1), len2 = strlen(num2);
	int i = 0, temp, j, k = 0;

	while(i < len2){
		if(num1[i] >= num2[i]){
			temp = num1[i] - num2[i];
			num1[k++] = temp + '0';
		}

		else {
			temp = (num1[i] - '0') + 10;
			num1[k++] = temp - (num2[i] - '0') + '0';

			j = i + 1;

			while(num1[j] == '0'){
				num1[j] = '9';
				++j;
			}

			num1[j] = num1[j] - 1;
		}
		i++;
	}

	i = strlen(num1) - 1;
	while(num1[i] == '0')
		--i;
	num1[i+1] = '\0';
}

void divide(char num[]){
	int i = 0, j = 0, temp = 0;
	while(i < strlen(num)){
		temp = temp*10 + (num[i] - '0');

		if(i != 0 && temp < 2){
			num[j++] = '0';
		}

		else if(temp >= 2){
			num[j++] = temp/2 + '0';
			temp = temp%2;
		}

		++i;
	}

	num[j] = '\0';
}

int main(){
	int p = 0, i, j, len1, len2;
	
	char num1[200], num2[200], temp1[200], temp2[200];
	while(p < 10){
		scanf("%s", num1);
		scanf("%s", num2);

		for(i = strlen(num1) - 1, j = 0; i >= 0; i--, j++)
			temp1[j] = num1[i];
		temp1[j] = '\0';

		for(i = strlen(num2) - 1, j = 0; i >= 0; i--, j++)
			temp2[j] = num2[i];
		temp2[j]= '\0';

		diff(temp1, temp2);

		for(i = strlen(temp1) - 1, j = 0; i >= 0; i--, j++)
			num1[j] = temp1[i];
		num1[j] = '\0';

		divide(num1);

		for(i = strlen(num1) - 1, j = 0; i >= 0; i--, j++)
			temp2[j] = num1[i];
		temp2[j] = '\0';

		for(i = strlen(num2) - 1, j = 0; i >= 0; i--, j++)
			temp1[j] = num2[i];
		temp1[j] = '\0';

		len1 = strlen(temp1);
		len2 = strlen(temp2);

		for(i = 0; i < len1 || i < len2; i++){
			if(i >= len2){
				temp2[i] = '0';
			}

			else if(i >= len1)
				temp1[i] = '0';
		}
		temp2[i] = '\0';
		temp1[i] = '\0';

		sum(temp2, temp1);

		for(i = strlen(temp2) - 1; i >= 0; i--)
			cout << temp2[i];
		cout << "\n";

		cout << num1;
		cout << "\n";
		++p;
	}
	return 0;
}
