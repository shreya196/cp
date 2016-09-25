#include <bits/stdc++.h>
#define MAX 50100
#define INF 999999999

using namespace std;

struct node {
	int l, r, t, b;
} temp, temp1, temp2;

int arr[MAX];
struct node tree[MAX * 4];

void createTree(int s, int e, int p){
	if(s > e)
		return;

	if(s == e){
		temp.l = arr[s];
		temp.r = arr[s];
		temp.b = arr[s];
		temp.t = arr[s];
		tree[p] = temp;
		return;
	}

	int m = (s + e)/2, sum;

	createTree(s, m, 2*p);
	createTree(m + 1, e, 2*p + 1);

	temp1 = tree[2*p];
	temp2 = tree[2*p + 1];

	temp.t = temp1.t + temp2.t;

	//Left Sum ------------------------------
	if(temp1.t + temp2.l > temp1.l)
		sum = temp1.t + temp2.l;
	else
		sum = temp1.l;

	if(sum < temp.t)
		sum = temp.t;

	temp.l = sum;
	//---------------------------------------

	//Right Sum -----------------------------
	if(temp2.t + temp1.r > temp2.r)
		sum = temp2.t + temp1.r;
	else
		sum = temp2.r;

	if(sum < temp.t)
		sum = temp.t;

	temp.r = sum;
	//---------------------------------------

	//Best Sum-------------------------------
	if(temp.l > temp.r)
		sum = temp.l;
	else
		sum = temp.r;

	if(sum < temp.t)
		sum = temp.t;

	if(sum < temp1.r + temp2.l)
		sum = temp1.r + temp2.l;

	temp.b = sum;
	//----------------------------------------

	tree[p] = temp;
}

int find(int qs, int qe, int s, int e, int p){
	
}

int main(){
	int n, i, m, x, y;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}

	createTree(1, n, 1);

	scanf("%d", &m);

	for(i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		//printf("%d\n", find(x, y, 1, n, 1));
	}
}