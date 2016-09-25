#include <bits/stdc++.h>

using namespace std;

int rem(int x, string y){
	int len = y.length(), i = 0;
	int temp = y[i] - '0';

	i++;
	while(i < len){
		while(temp < x){
			temp = temp*10 + (y[i] - '0');
			i++;
		}

		temp = temp % x;
	}

	if(temp > x)
		temp = temp%x;

	return temp;
}

int main(){
	int x;
	string y;
	cin >> x;
	cin >> y;
	cout << rem(x, y) << "\n";
}