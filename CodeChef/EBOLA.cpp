#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

int weight[MAX], v[MAX], done[MAX], weightBackUp[MAX];
vector<int> graph[MAX];
vector<int> ans;
map<int, int> maxs;

typedef pair<int, int> pii;

int cmpfunc (const void * a, const void * b){
   return ( *(int*)b - *(int*)a );
}

void find(int s, int x, int n){
	queue <int> q1, q2, q3, q4;

	for(int i = 1; i <= n; i++){
		v[i] = 0;
		done[i] = 0;
	}

	int curDist, cur, reqDist = 0, i, maxVal, maxIndex, count = 0, temp, oneTemp;
	int curMax, curMaxDist;

	q1.push(s);
	q2.push(0);
	q3.push(s);
	q4.push(0);
	done[s] = 1;

	while(!q1.empty()){
		maxVal = -1, maxIndex = temp;

		while(!q4.empty() && q4.front() == reqDist){
			curMax = q3.front();
			q3.pop();
			q4.pop();

			for(i = 0; i < graph[curMax].size(); i++){
				temp = graph[curMax][i];
				if(v[temp] != 1 && done[temp] != 1){
					if(maxs.find(weight[temp]) != maxs.end()){
						if(weight[temp] > maxVal){
							maxVal = weight[temp];
							maxIndex = temp;
						}
					}
				}
			}
		}

		if(maxVal != -1) {
			ans.push_back(maxIndex);
			v[maxIndex] = 1;
			++count;
		}

		else {
			for(i = 1; i <= n; i++){
				if(v[i] != 1 && done[i] != 1){
					if(weight[i] > maxVal){
						maxVal = weight[i];
						maxIndex = i;
					}
				}
			}

			if(maxVal != -1){
				ans.push_back(maxIndex);
				v[maxIndex] = 1;
				++count;
			}

			else {
				ans.push_back(1);
				v[1] = 1;
				++count;
			}
		}

		if(count == x)
			break;

		while(q2.front() == reqDist){
			curDist = q2.front();
			cur = q1.front();
			q2.pop();
			q1.pop();

			for(i = 0; i < graph[cur].size(); i++){
				temp = graph[cur][i];

				if(v[temp] != 1 && done[temp] != 1){
						q1.push(temp);
						q3.push(temp);
						q2.push(reqDist + 1);
						q4.push(reqDist + 1);
						done[temp] = 1;
				}
			}
		}

		++reqDist;
	}
}

int main(){
	int n, m, k, s, i, x, y;
	scanf("%d %d %d %d", &n, &m, &k, &s);

	for(i = 1; i <= n; i++){
		scanf("%d", &weight[i]);
		weightBackUp[i] = weight[i];
	}

	for(i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	weightBackUp[0] = -1;
	qsort(weightBackUp, n + 1, sizeof(int), cmpfunc);
	for(i = 0; i < k; i++){
		maxs[weightBackUp[i]] = 1;
	}

	find(s, k, n);

	for(i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	for(i = 1; i <= k - ans.size(); i++)
		cout << 1 << " ";

	cout << "\n";
}