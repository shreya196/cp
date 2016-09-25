#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, i, c1, c2, flag;
	cin >> t;

	string str;
	while(t--){
		cin >> str;
		c1 = 0;
		c2 = 0;
		flag = 0;
		for(i = 0; i < str.length(); i++){
			if(str[i] == '1')
				++c1;
			else
				++c2;
		}

		if(c1 == 1 || c2 == 1)
			cout << "Yes\n";

		else
			cout << "No\n";
	}

	return 0;
}