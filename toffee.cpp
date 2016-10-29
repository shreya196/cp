#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int inf = (1 << 29);

vector < vector < pair < int, int > > > graph;
vector < pair < int, int > > vpii;

int n, e, t, m;

int dijkstra()
{
    int sol = 0;

    vector < int > dist(n, inf);
    dist[e] = 0;

    set < pair < int, int > > ordered;
    ordered.insert(make_pair(0, e));

    int node, cost;
    while (!ordered.empty())
    {
        node = (*ordered.begin()).second;
        cost = (*ordered.begin()).first;

        ordered.erase(ordered.begin());

        sol++;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextn = graph[node][i].first;
            int nextc = graph[node][i].second;

            if (cost + nextc <= t && cost + nextc < dist[nextn])
            {
                if (dist[nextn] != inf)
                {
                    ordered.erase(make_pair(dist[nextn], nextn));
                }
                dist[nextn] = cost + nextc;
                ordered.insert(make_pair(dist[nextn], nextn));
            }
        }
    }

    return sol;
}

int main()
{
    scanf("%d %d %d %d", &n, &e, &t, &m);
    e--;

    graph.insert(graph.begin(), n, vpii);

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[b-1].push_back(make_pair(a-1, c));
    }

    printf("%d\n", dijkstra());

    return 0;
}
