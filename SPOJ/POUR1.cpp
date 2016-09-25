#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
	if(x == 0)
		return y;

	return gcd(y%x, x);
}

int find(int s1, int s2, int d){
	int temp;
	int vessel1, vessel2, count, count2;

	if(s2 > s1){
		temp = s1;
		s1 = s2;
		s2 = temp;
	}

	if(d % gcd(s2, s1) != 0){
		return -1;
	}

	else {
		vessel1 = s1, vessel2 = 0, count = 0;
		while(vessel1 != d && vessel2 != d){
			if(vessel1 >= (s2 - vessel2)){
				vessel1 -= (s2 - vessel2);
				vessel2 = 0;
			}

			else {
				vessel2 += vessel1;
				vessel1 = s1;
			}

			count += 2;
		}

		vessel1 = 0, vessel2 = s2, count2 = 0;
		while(vessel1 != d && vessel2 != d){
			if(vessel2 >= (s1 - vessel1)){
				vessel2 -= (s1 - vessel1);
				vessel1 = 0;
			}

			else {
				vessel1 += vessel2;
				vessel2 = s2;
			}

			count2 += 2;
		}

		if(count2 < count)
			count = count2;

		return count;
	}
}

int main(){
	int x, p = 0, temp;
	scanf("%d", &x);

	int r, s, t;
	while(p < x){
		scanf("%d %d %d", &s, &t, &r);

		if(s < r && t < r)
			temp = -1;

		else if(s == r || t == r)
			temp = 1;

		else
			temp = find(s, t, r);

		printf("%d\n", temp);

		++p;
	}

	return 0;
}