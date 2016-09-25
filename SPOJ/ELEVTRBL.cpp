#include <bits/stdc++.h>

using namespace std;

long long int dist[1000001];

void bfs(long long int f, long long int s, long long int g, long long int u, long long int d){
	long long int i = 0, temp, temp2;

	while(i < 1000001){
		dist[i] = -1;
		i++;
	}

	queue <long long int> q;
	q.push(s);
	dist[s] = 0;

	while(!q.empty()){
		temp = q.front();
		q.pop();

		if(temp == g){
			printf("%lld\n", dist[temp]);
			return;
		}

		if(u != 0){
			temp2 = temp + u;
			if(dist[temp2] == -1){
				q.push(temp2);
				dist[temp2] = dist[temp] + 1;
			}
		}

		if(d != 0){
			temp2 = temp - d;
			if(dist[temp2] == -1){
				q.push(temp2);
				dist[temp2] = dist[temp] + 1;
			}
		}
	}

	printf("use the stairs\n");
}

int main(){
	long long int f, s, g, u, d;
	scanf("%lld %lld %lld %lld %lld", &f, &s, &g, &u, &d);
	bfs(f, s, g, u, d);
}