#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
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

bool TopoBfs()
{
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto neighbour : graph[i])
        {
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            visited.insert(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        count++;
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

    // If count of visited nodes is less than the total number of nodes,
    // then there is a cycle in the graph.
    return count < v;
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

    if (TopoBfs())
    {
        cout << "Graph contains a cycle";
    }
    else
    {
        cout << "No cycle in the graph";
    }

    return 0;
}
