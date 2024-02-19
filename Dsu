#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &parent, int x)
{
    // this method returns which group/cluster x belongs to
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]); // by path compression
}
void Union(vector<int> &parent, vector<int> &rank, int a, int b)
{
    a = find(parent, a);
    b = find(parent, b);
    if (rank[a] < rank[b])
    {
        parent[a] = b;
        rank[b]++;
    }
    else if (rank[a] >= rank[b])
    {
        parent[b] = a;
        rank[a]++;
    }
    // thats all for disjoint set union
}
int main()
{
    int n, m;
    cin >> n >> m;
    // n== number of elements  m==no of queries
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, x, y);
        }
        else
        {
            int x;
            cin >> x;
            cout << find(parent, x) << endl;
        }
    }

    return 0;
}
