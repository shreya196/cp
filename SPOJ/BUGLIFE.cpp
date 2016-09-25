#include <bits/stdc++.h>
#define MAX 2010

using namespace std;

int graph[MAX][MAX], done[MAX];
char gender[MAX];

int check(int r, int n){
	queue <int> q;
	int c, i, curGender, reqGender;

	q.push(r);
	done[r] = 1;
	gender[r] = 'm';

	while(!q.empty()){
		c = q.front();
		q.pop();
		curGender = gender[c];

		if(curGender == 'm')
			reqGender = 'f';
		else
			reqGender = 'm';

		for(i = 1; i <= n; i++){
			if(graph[c][i]){
				if(done[i]){
					if(gender[i] != reqGender)
						return 0;
				}

				else {
					q.push(i);
					done[i] = 1;
					gender[i] = reqGender;
				}
			}
		}
	}

	return 1;
}

int main(){
	int x, p = 1, n, r, s, ans;
	long long int y, i, j;
	scanf("%d", &x);

	while(p <= x){
		scanf("%d %lld", &n, &y);

		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				graph[i][j] = 0;
			}
		}

		for(i = 0; i < y; i++){
			scanf("%d %d", &r, &s);
			graph[r][s] = 1;
			graph[s][r] = 1;
		}

		for(i = 1; i <= n; i++){
			done[i] = 0;
		}

		for(i = 1; i <= n; i++){
			if(!done[i]){
				ans = check(i, n);
				if(ans == 0)
					break;
			}
		}

		printf("Scenario #%d:\n", p);

		if(ans == 0){
			printf("Suspicious bugs found!\n");
		}
		else {
			printf("No suspicious bugs found!\n");
		}
		++p;
	}

	return 0;
}