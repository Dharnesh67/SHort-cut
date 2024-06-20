#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edgelist;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgelist.push_back({u, v, w});
    }
    vector<int> dis(v, INT_MAX);
    int src;
    cout << "enter the source: ";
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= v - 1; i++)
    {
        for (auto &edge : edgelist)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dis[u] != INT_MAX && dis[u] + w < dis[v])
            {
                dis[v] = w + dis[u];
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << dis[i] << " ";
    }
}