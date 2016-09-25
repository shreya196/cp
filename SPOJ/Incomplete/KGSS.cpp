#include <bits/stdc++.h>
#define MAX 100100
#define INF 999999999

using namespace std;

struct node {
	int max, smax;
};

int arr[MAX];
struct node tree[4*MAX];

void createTree(int s, int e, int p){
	struct node temp, temp1, temp2;
	if(s > e)
		return;

	if(s == e){
		temp.max = arr[s];
		temp.smax = -INF;
		tree[p] = temp;
		return;
	}

	int m = (s + e)/2;

	createTree(s, m, 2*p);
	createTree(m + 1, e, 2*p + 1);

	temp1 = tree[2*p];
	temp2 = tree[2*p + 1];

	if(temp1.max > temp2.max){
		temp.max = temp1.max;
		if(temp2.max > temp1.smax)
			temp.smax = temp2.max;
		else
			temp.smax = temp1.smax;
	}

	else {
		temp.max = temp2.max;
		if(temp1.max > temp2.smax)
			temp.smax = temp1.max;
		else
			temp.smax = temp2.smax;
	}

	tree[p] = temp;
}

void updateTree(int q, int s, int e, int p){
	struct node temp, temp1, temp2;
	if(s > e || s > q || e < q)
		return;

	if(s == e){
		temp.max = arr[q];
		temp.smax = -INF;
		tree[p] = temp;
		return;
	}

	int m = (s + e)/2;

	updateTree(q, s, m, 2*p);
	updateTree(q, m + 1, e, 2*p + 1);

	temp1 = tree[2*p];
	temp2 = tree[2*p + 1];

	if(temp1.max > temp2.max){
		temp.max = temp1.max;
		if(temp2.max > temp1.smax)
			temp.smax = temp2.max;
		else
			temp.smax = temp1.smax;
	}

	else {
		temp.max = temp2.max;
		if(temp1.max > temp2.smax)
			temp.smax = temp1.max;
		else
			temp.smax = temp2.smax;
	}

	tree[p] = temp;
}

struct node find(int qs, int qe, int s, int e, int p){
	struct node temp, temp1, temp2;

	if(s > e || qs > e || qe < s){
		temp.max = -INF;
		temp.smax = -INF;
		return temp;
	}

	if(s >= qs && e <= qe){
		return tree[p];
	}

	int m = (s + e)/2;
	temp1 = find(qs, qe, s, m, 2*p);
	temp2 = find(qs, qe, m + 1, e, 2*p + 1);

	if(temp1.max > temp2.max){
		temp.max = temp1.max;
		if(temp2.max > temp1.smax)
			temp.smax = temp2.max;
		else
			temp.smax = temp1.smax;
	}

	else {
		temp.max = temp2.max;
		if(temp1.max > temp2.smax)
			temp.smax = temp1.max;
		else
			temp.smax = temp2.smax;
	}

	return temp;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n, i;
	cin >> n;

	for(i = 1; i <= n; i++)
		cin >> arr[i];

	createTree(1, n, 1);

	int t;
	cin >> t;

	char x;
	int y, z;
	struct node temp;
	while(t--){
		cin >> x >> y >> z;
		if(x == 'Q'){
			temp = find(y, z, 1, n, 1);
			cout << temp.max + temp.smax << "\n";
		}

		else {
			arr[y] = z;
			updateTree(y, 1, n, 1);
		}
	}
}