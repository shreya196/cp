#include <bits/stdc++.h>

using namespace std;

int main(){
	int r, i, j, k, x;
	long long int sum, rad;

	vector<long long int> q1, q2, q3;

	scanf("%d", &x);
	r = x*x;

	for(i = 1; i <= 20*r; i++){
		for(j = i; j <= 20*r; j++){
			for(k = j ; k <= 20*r; k++){

				if((i + j) < k || (j + k) < i || (k + i) < j){
					continue;
				}

				sum = (i + j + k);

				if(sum%2 != 0){
					continue;
				}

				sum = sum/2;
				rad = (sum - i)*(sum - j)*(sum - k);

				if(rad == r*sum){
					q1.push_back(i);
					q2.push_back(j);
					q3.push_back(k);
				}
			}
		}
	}
	
	cout << q1.size() << "\n";
	for(i = 0; i < q1.size(); i++){
		cout << q1[i] << " " << q2[i] << " " << q3[i] << "\n";
	}
}