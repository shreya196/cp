#include <bits/stdc++.h>
#define MAXSIZE 110000
#define MAX 1000100

using namespace std;

int arr[MAXSIZE], tree[MAXSIZE * 4];
int divisors[MAX + 10], seieve[MAX + 10];

void init(){
	int i, j, prime[MAX], k = 0;

	for(i = 2; i*i <= MAX; i++){
		if(seieve[i] == 0)
			prime[k++] = i;

		for(j = 2*i; j <= MAX; j += i){
			seieve[j] = 1;
		}
	}

	for(; i <= MAX; i++){
		if(seieve[i] == 0){
			prime[k++] = i;
		}
	}

	divisors[1] = 1;
	for(i = 2; i <= MAX; i++){
		if(seieve[i] == 0){
			divisors[i] = i;
			continue;
		}

		for(j = 0; prime[j] <= i/2; j++){
			if(i % prime[j] == 0){
				divisors[i] = prime[j];
				break;
			}
		}

		if(divisors[i] == 0)
			divisors[i] = 1;
	}
}

void createTree(int s, int e, int p){
	if(s > e)
		return;

	if(s == e){
		//tree[p] = divisors[arr[s]];
		tree[p] = arr[s];
		return;
	}

	int m = (s + e)/2;
	createTree(s, m, 2*p);
	createTree(m + 1, e, 2*p + 1);

	if(divisors[tree[2*p]] > divisors[tree[2*p + 1]])
		tree[p] = tree[2*p];

	else
		tree[p] = tree[2*p + 1];
}

int find(int qs, int qe, int s, int e, int p){
	if(tree[p] == 1)
		return 1;

	if(s > e || qs > e || qe < s)
		return -1;

	if(s >= qs && e <= qe)
		return divisors[tree[p]];

	int m = (s + e)/2;
	int ans1 = find(qs, qe, s, m, 2*p);
	int ans2 = find(qs, qe, m + 1, e, 2*p + 1);

	if(ans1 > ans2)
		return divisors[ans1];

	else
		return divisors[ans2];
}

void update(int qs, int qe, int s, int e, int p){
	if(tree[p] == 1)
		return;

	if(s > e || s > qe || e < qs)
		return;

	if(s == e){
		tree[p] = tree[p] / divisors[tree[p]];
		return;
	}

	int m = (s + e)/2;
	update(qs, qe, s, m, 2*p);
	update(qs, qe, m + 1, e, 2*p + 1);

	if(divisors[tree[2*p]] > divisors[tree[2*p + 1]])
		tree[p] = tree[2*p];

	else
		tree[p] = tree[2*p + 1];
}


int main(){

	init();

	int t, n, m, i, x, y, z, j, flag;
	scanf("%d", &t);

	while(t--){
		memset(tree, 0, sizeof(tree));
		scanf("%d %d", &n, &m);

		for(i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
		}

		createTree(1, n, 1);

		for(i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &z);
			flag = 0;
			if(x == 0){
				update(y, z, 1, n, 1);
			}

			else {
				cout <<	find(y, z, 1, n, 1) << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}