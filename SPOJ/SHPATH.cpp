#include <bits/stdc++.h>
#define MAX 100002
#define INF 9999999999

using namespace std;

typedef pair<int, int> pii;

long long int price[MAX];
int done[MAX];
vector<struct edge> graph[MAX];

struct compare {
	bool operator()(const pii& l, const pii& r){
		return l.second > r.second;
	}
};

struct edge {
	int v;
	int price;
} temp;

long long int dijkstra(int s, int d, int n){
	priority_queue <pii, vector<pii>, compare> q;
	int i, cur, dis;

	for(i = 1; i <= n; i++){
		price[i] = INF;
		done[i] = 0;
	}

	q.push(make_pair(s, 0));
	price[s] = 0;

	while(!q.empty()){
		cur = q.top().first;
		dis = q.top().second;
		q.pop();

		if(done[cur])
			continue;

		done[cur] = 1;
		for(i = 0; i < graph[cur].size(); i++){
			if(!done[graph[cur][i].v] && price[graph[cur][i].v] > dis + graph[cur][i].price){
				price[graph[cur][i].v] = dis + graph[cur][i].price;
				q.push(make_pair(graph[cur][i].v, price[graph[cur][i].v]));
			}
		}
	}

	return price[d];
}

void fastRead_int(int *a)
{
    register char c=0;
    while (c<33) c = getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

void fastRead_string(char *str)
{
    register char c=0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c > 65)
    {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}

int main(){
	int t, i = 0, n, j, x, k, s, d;
	fastRead_int(&t);

	while(i < t){
		map <string, int> names;
		fastRead_int(&n);
		for(j = 1; j <= n; j++){
			char aName[11];
			fastRead_string(aName);
			string tempStr(aName);
			names[tempStr] = j;
			fastRead_int(&x);
			for(k = 1; k <= x; k++){
				fastRead_int(&(temp.v));
				fastRead_int(&(temp.price));
				graph[j].push_back(temp);
			}
		}

		fastRead_int(&x);
		for(k = 0; k < x; k++){
			char aName[11], aName2[11];
			fastRead_string(aName);
			string source(aName);
			fastRead_string(aName2);
			string dest(aName2);

			s = names.find(source)->second;
			d = names.find(dest)->second;

			cout << dijkstra(s, d, n) << "\n";
		}

		for(j = 1; j <= n; j++){
			graph[j].clear();
		}

		i++;
	}
	return 0;
}