#include <bits/stdc++.h>
// floyd warshall algorithm is used to find the shortest path between all pairs of vertices in a graph not matter what is source and destination
//  it is used to find the shortest path between all pairs of vertices in a graph not matter what is source and destination
// we will have the 2D distance Matrix of size n*n where n is the number of vertices in the graph and the value of the Matrix will be the shortest distance between the ithe and jth vertex
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0; // disance khud se khud tak 0 hoga
    }
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        dis[u][v] = w;
    }
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][via] < 1e9 && dis[via][j] < 1e9)
                { // Check to avoid integer overflow
                    dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}