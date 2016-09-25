#include <bits/stdc++.h>
#define MAX 101000
#define INF 9999999999

using namespace std;

struct tckt {
	int v;
	long long int p;
};

int arr[MAX];
vector<struct tckt> tickets[MAX];
long long int minP[MAX];

long long int findMin(int s){
	if(minP[s] != INF)
		return minP[s];

	int i, j, cur;
	long long int temp1, temp2;
	struct tckt tempTckt;

	for(i = 0; i < tickets[s].size(); i++){
		tempTckt = tickets[s][i];
		cur = s;

		for(j = 0; j < tempTckt.v; j++){
			cur = arr[cur];

			temp2 = findMin(cur);
			temp1 = temp2 + tempTckt.p;

			if(temp1 < minP[s])
				minP[s] = temp1;

			if(cur == 1)
				break;
		}	
	}

	return minP[s];
}

int main(){
	int n, m, i, x, y;
	long long int p;

	scanf("%d %d", &n, &m);

	for(i = 1; i <= n; i++)
		minP[i] = INF;

	for(i = 1; i <= (n - 1); i++){
		scanf("%d %d", &x, &y);
		arr[x] = y;
	}

	struct tckt temp;
	minP[1] = 0;

	for(i = 1; i <= m; i++){
		scanf("%d %d %lld", &x, &y, &p);
		temp.v = y;
		temp.p = p;
		tickets[x].push_back(temp);
	}

	scanf("%d", &x);
	for(i = 1; i <= x; i++){
		scanf("%d", &y);
		printf("%lld\n", findMin(y));
	}

	return 0;
}
