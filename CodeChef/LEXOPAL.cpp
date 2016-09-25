#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, i, j, flag;
	cin >> t;

	string str;
	while(t--){
		cin >> str;
		char arr[str.length() + 1];

		arr[str.length()] = '\0';
		flag = 0;
		for(i = 0, j = str.length() - 1; i < j; i++, j--){
			if(str[i] != str[j]){
				if(str[i] == '.'){
					arr[i] = str[j];
					arr[j] = str[j];
				}

				else if(str[j] == '.'){
					arr[j] = str[i];
					arr[i] = str[i];
				}

				else{
					flag = 1;
					break;
				}
			}

			else{
				if(str[i] != '.'){
					arr[i] = str[i];
					arr[j] = str[j];
				}

				else {
					arr[i] = 'a';
					arr[j] = 'a';
				}
			}
		}

		if(flag == 1)
			cout << "-1\n";

		else {
			if(i == j){
				if(str[i] == '.')
					arr[i] = 'a';
				else
					arr[i] = str[i];
			}
			
			cout << arr << "\n";
		}
	}
}