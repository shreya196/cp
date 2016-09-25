#include <bits/stdc++.h>
#define MAX 20010

using namespace std;

int strIndex, smallest, ans, cuts;
char arr[MAX];

void count(long long int size){
	if(arr[strIndex] == '1'){
		++cuts;

		++strIndex;
		count(size+1);

		++strIndex;
		count(size+1);

	}

	else{
		if(size > smallest){
			smallest = size;
			ans = cuts;
		}
	}
}

int main(){
	int p = 0, n;
	while(p < 10){
		scanf("%d", &n);
		scanf("%s", arr);

		strIndex = 0, ans = 0, cuts = 0, smallest = 0;

		count(1);
		cout << ans << "\n";

		++p;
	}
}