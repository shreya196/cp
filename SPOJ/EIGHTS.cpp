#include <bits/stdc++.h>

int main(){
    int t, p = 0;
    scanf("%d", &t);

    unsigned long long int x;

    while(p < t){
    	scanf("%llu", &x);
    	printf("%llu\n", (x - 1)*250 + 192);
    	++p;
    }
}