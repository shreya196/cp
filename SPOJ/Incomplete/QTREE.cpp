#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

struct node {
	int v;
	long long int price;
} temp;

typedef pair <int, int> pii;

vector <struct node> graph[MAX];
pii arr[MAX], pred[MAX];
int done[MAX];

long long int find(int s, int d, int n){
	stack <int> q;
	stack <long long int> max;
	int i, cur;
	long long int ans = 0;

	for(i = 0; i <=n; i++){
		done[i] = 0;
		pred[i] = make_pair(-1, 0);
	}

	q.push(s);
	max.push(0);

	while(!q.empty()){
		cur = q.top();
		q.pop();

		if(cur == d)
			break;

		if(done[cur])
			continue;

		max.pop();

		for(i = 0; i < graph[cur].size(); i++){
			if(!done[graph[cur][i].v]){
				temp = graph[cur][i];
				pred[temp.v] = make_pair(cur, temp.price);
				q.push(temp.v);
			}
		}

		done[cur] = 1;
	}

	cur = d;
	while(pred[cur].first != -1){
		if(pred[cur].second > ans)
			ans = pred[cur].second;
		cur = pred[cur].first;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t, p = 0, n, i, x, y;
	int s, d;
	long long int z;
	cin >> t;
	string str;

	while(p < t){
		cin >> n;

		for(i = 0; i <= n; i++)
			graph[i].clear();

		for(i = 0; i < (n-1); i++){
			cin >> x >> y >> z;
			temp.v = y;
			temp.price = z;
			graph[x].push_back(temp);
			temp.v = x;
			temp.price = z;
			graph[y].push_back(temp);
			arr[i] = make_pair(x, y);
		}

		while(1){
			
			cin >> str;
			if(str == "DONE\0")
				break;

			else {
				cin >> x >> y;
				if(str == "QUERY\0"){
					cout << find(x, y, n) << "\n";
				}

				else {
					s = arr[x - 1].first;
					d = arr[x - 1].second;
					for(i = 0; i < graph[s].size(); i++){
						if(graph[s][i].v == d){
							graph[s][i].price = y;
							break;
						}
					}
				}

			}
		}

		++p;
	}

	return 0;
}