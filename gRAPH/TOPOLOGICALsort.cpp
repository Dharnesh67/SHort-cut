#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back
#define eb emplace_back
vector<list<int>> graph;
void add(int a, int b)
{
    graph[a].push_back(b);
}
void topo(int n)
{
    vi indegree(n, 0);
    f(i, 0, n)
    {
        int node = i;
        for (int &x : graph[node])
        {
            indegree[x]++;
        }
    }
    queue<int> q;
    vector<bool> vis(n, 0);
    f(i, 0, n)
    {
        if (indegree[i] == 0)
        {
            vis[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int &x : graph[node])
        {
            if (!vis[x])
            {

                indegree[x]--;
                if (indegree[x] == 0)
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
            else
            {
                cout << "Cycle detected";
                return;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (indegree[i] != 0)
        {
            cout << "Cycle detected";
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, e;
    cin >> n >> e;
    graph.resize(n, list<int>());
    f(i, 0, e)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    topo(n);
    return 0;
}

