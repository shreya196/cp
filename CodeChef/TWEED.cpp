#include <bits/stdc++.h>

using namespace std;

int arr[100000][100000];

int main(){
	int t;
	cin >> t;

	int x, i;
	string name;
	while(t--){
		cin >> x >> name;
		int arr[x];

		for(i = 0; i < x; i++)
			cin >> arr[i];

		if(x == 1 && name == "Dee" && arr[0]%2 == 0)
			cout << "Dee\n";

		else
			cout << "Dum\n";
	}
	return 0;
}