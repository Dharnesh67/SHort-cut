#include <iostream>   // TOPOLOGICAL SORT USING KAHN's ALGORITHMN
#include <vector>   // TOPOLOGICAL SORT USING KAHN's ALGORITHMN
#include <list>   // TOPOLOGICAL SORT USING KAHN's ALGORITHMN
#include <queue>   // TOPOLOGICAL SORT USING KAHN's ALGORITHMN
#include <unordered_set>   // TOPOLOGICAL SORT USING KAHN's ALGORITHMN
using namespace std;
int v;
vector<list<int>> graph;
unordered_set<int> visited;
void add_edges(int a, int b, bool bidir = true)
{
    graph[a].push_back(b);
    if (bidir)
        graph[b].push_back(a);
}
void TopoBfs()
{
    // Kahn's Algorithmn
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto neighbour : graph[i])
        { /* i--> neighbour*/
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    // unordered_set<int> visited;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            visited.insert(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (auto neighbour : graph[node])
        {
            if (!visited.count(neighbour))
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}
int main()
{
    cin >> v;
    int e;
    cin >> e;
    visited.clear();
    graph.resize(v, list<int>());
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        add_edges(x, y, false);
    }
    TopoBfs();
    return 0;
}
