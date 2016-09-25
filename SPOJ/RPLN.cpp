#include <bits/stdc++.h>
#define MAX 100200
#define INF 999999999

using namespace std;

int arr[MAX], tree[MAX * 4];

void createTree(int s, int e, int p){
	if(s > e)
		return;

	if(s == e){
		tree[p] = arr[s];
		return;
	}

	int m = (s + e)/2;

	createTree(s, m, 2*p);
	createTree(m + 1, e, 2*p + 1);

	if(tree[2*p] < tree[2*p + 1])
		tree[p] = tree[2*p];

	else
		tree[p] = tree[2*p + 1];
}

int find(int qs, int qe, int s, int e, int p){
	if(s > e || qs > e || qe < s)
		return INF;

	if(s >= qs && e <= qe){
		return tree[p];
	}

	int m = (s + e)/2;
	int ans1 = find(qs, qe, s, m, 2*p);
	int ans2 = find(qs, qe, m + 1, e, 2*p + 1);

	if(ans1 < ans2)
		return ans1;

	else
		return ans2;
}

int main(){
	int t, n, q, x, y, i, p = 0;
	scanf("%d", &t);

	while(t--){
		++p;
		memset(tree, INF, sizeof(tree));

		scanf("%d %d", &n, &q);

		for(i = 1; i <= n; i++)
			scanf("%d", &arr[i]);

		createTree(1, n, 1);

		printf("Scenario #%d:\n", p);
		for(i = 1; i <= q; i++){
			scanf("%d %d", &x, &y);
			printf("%d\n", find(x, y, 1, n, 1));
		}
	}

	return 0;
}