#include <bits/stdc++.h>

using namespace std;

int chars[26];

int main(){
	string x, temp;
	cin >> x;

	int i;
	char p;
	for(i = 0; i < x.length(); i++){
		p = x[i];
		chars[p - 'a'] = 1;
	}

	int n, j, flag;
	cin >> n;

	for(i = 0; i < n; i++){
		cin >> temp;
		flag = 0;
		for(j = 0; j < temp.length(); j++){
			p = temp[j];
			if(chars[p - 'a'] != 1){
				flag = 1;
				break;
			}
		}

		if(flag == 0)
			cout << "Yes\n";

		else
			cout << "No\n";
	}
}