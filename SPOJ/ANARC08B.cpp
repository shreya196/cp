#include <bits/stdc++.h>

using namespace std;

int main(){
	string expression;
	string list[10] = {"063", "010", "093", "079", "106", "103", "119", "011", "127", "107"};
	int count, j;
	long long int i, ans, tempAns, trailing = 0, flag = 0;

	while(1){
		cin >> expression;

		if(expression == "BYE"){
			break;
		}

		i = 0, count = 0;
		long long int givenNo[2] = {0, 0}, noCount = 0;
		char temp[3];
		trailing = 0, flag = 0;

		while(i < expression.length()){
			if(expression[i] == '+'){
				i++;
				noCount += 1;
				continue;
			}
			else if(expression[i] == '=')
				break;

			temp[count] = expression[i];
			count++;

			if(count == 3){
				count = 0;
				for(j = 0; j < 10; j++){
					if(list[j][0] == temp[0] && list[j][1] == temp[1] && list[j][2] == temp[2]){
						givenNo[noCount] = givenNo[noCount]*10 + j;
						break;
					}
				}
			}
			i++;
		}

		ans = givenNo[0] + givenNo[1];
		tempAns = 0;

		while(ans > 0){
			tempAns = tempAns*10 + (ans%10);
			if(ans%10 != 0)
				flag = 1;
			if(ans%10 == 0 && flag == 0)
				trailing++;
			ans = ans/10;
		}

		ans = tempAns;
		cout << expression;

		if(ans == 0)
			printf("063");

		while(ans > 0){
			tempAns = ans % 10;
			ans = ans / 10;
			cout << list[tempAns];
		}
		while(trailing != 0){
			cout << "063";
			trailing--;
		}
		printf("\n");
	}

	return 0;
}
