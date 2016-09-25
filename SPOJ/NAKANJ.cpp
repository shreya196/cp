#include <bits/stdc++.h>

using namespace std;

char boxes[100][3];
int dist[100];

int bfs(int start, int end){
	queue <int> q;
	int i = 1, temp2, some;
	char temp[2];

	while(i < 100)
		dist[i++] = -1;

	q.push(start);
	dist[start] = 0;

	int c = 0;
	while(!q.empty()){
		temp2 = q.front();
		++c;
		temp[0] = boxes[temp2][0];
		temp[1] = boxes[temp2][1];
		q.pop();
		if(temp[0] == boxes[end][0] && temp[1] == boxes[end][1]){
			cout << "c: " << c << "\n";
			return dist[(temp[0] - 'a')*8 + (temp[1] - '0')];
		}

		if(temp[1] + 2 <= '8'){
			if(temp[0] - 1 >= 'a'){
				some = (temp[0] - 1 - 'a')*8 + (temp[1] + 2 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
			if(temp[0] + 1 <= 'h'){
				some = (temp[0] + 1 - 'a')*8 + (temp[1] + 2 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
		}

		if(temp[1] - 2 > '0'){
			if(temp[0] - 1 >= 'a'){
				some = (temp[0] - 1 - 'a')*8 + (temp[1] - 2 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
			if(temp[0] + 1 <= 'h'){
				some = (temp[0] + 1 - 'a')*8 + (temp[1] - 2 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
		}

		if(temp[0] + 2 <= 'h'){
			if(temp[1] - 1 >= '1'){
				some = (temp[0] + 2 - 'a')*8 + (temp[1] - 1 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
			if(temp[1] + 1 <= '8'){
				some = (temp[0] + 2 - 'a')*8 + (temp[1] + 1 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
		}

		if(temp[0] - 2 >= 'a'){
			if(temp[1] - 1 >= '1'){
				some = (temp[0] - 2 - 'a')*8 + (temp[1] - 1 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
			if(temp[1] + 1 <= '8'){
				some = (temp[0] - 2 - 'a')*8 + (temp[1] + 1 - '0');
				if(dist[some] == -1){
					q.push(some);
					dist[some] = dist[temp2] + 1;
				}
			}
		}
	}
}

int main(){
	char p;
	int j, count = 1;
	for(p = 'a'; p <= 'h'; p++){
		for(j = '1'; j <= '8'; j++){
			boxes[count][0] = p;
			boxes[count][1] = j;
			boxes[count][3] = '\0';
			count++;
		}
	}

	int t, i = 0;
	scanf("%d", &t);
	char arr1[3], arr2[3];
	int temp1, temp2;

	while(i < t){
		scanf("%s %s", arr1, arr2);
		temp1 = (arr1[0] - 'a')*8 + (arr1[1] - '0');
		temp2 = (arr2[0] - 'a')*8 + (arr2[1] - '0');
		printf("%d\n", bfs(temp1, temp2));
		i++;
	}
}