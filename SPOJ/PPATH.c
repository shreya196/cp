#include <bits/stdc++.h>

using namespace std;

int seive[10000], prime[1065], maxN = 0;
int graph[1065][1065];

int binarySearch(int x){
	int start = 0, end = maxN - 1, mid;
	while(start <= end){
		mid = (start + end)/2;
		if(prime[mid] == x)
			return mid;
		if(prime[mid] > x)
			end = mid - 1;
		else if(prime[mid] < x)
			start = mid + 1;
	}
	return -1;
}

int bfs(int start, int end){
	int visited[1065], dist[1065];
	queue <int> q;
	int temp, i;

	for(i = 0; i < maxN; i++){
		visited[i] = 0;
		dist[i] = 0;
	}

	q.push(start);
	visited[start] = 1;
	dist[start] = 0;

	while(!q.empty()){
		temp = q.front();
		q.pop();

		if(prime[temp] == prime[end]){
			return dist[temp];
		}

		for(i = 0; i < maxN; i++){
			if(graph[temp][i] && !visited[i]){
				q.push(i);
				visited[i] = 1;
				dist[i] = dist[temp] + 1;
				
			}
		}
	}
}

int main(){
	int i, j;
	int q, r, temp, num, r1, k, temp2, perNum;
	int n1, n2;

	for(i = 2; i*i < 10000; i++){
		if(!seive[i]){
			for(j = i*2; j < 10000; j += i){
				seive[j] = 1;
			}
		}
	}

	for(i = 1000; i <= 9999; i++){
		if(!seive[i]){
			prime[maxN] = i;
			maxN++;
		}
	}

	for(i = 0; i < maxN; i++){
		perNum = prime[i];
		num = prime[i];
		for(j = 10; j <= 10000; j *= 10){
			r = perNum%j;
			num = perNum - r;
			r1 = r%(j/10);
			for(k = 0; k <= 9; k++){
				temp = num + k*(j/10) + r1;
				if(!seive[temp]){
					if(temp > 1000){
						temp2 = binarySearch(temp);
						graph[i][temp2] = 1;
					}
				}
			}
		}
	}

	int t;
	i = 0;
	scanf("%d", &t);
	while(i < t){
		scanf("%d %d", &n1, &n2);
		n1 = binarySearch(n1);
		n2 = binarySearch(n2);

		int ans = bfs(n1, n2);
		printf("%d\n", ans);
		i++;
	}

	return 0;
}