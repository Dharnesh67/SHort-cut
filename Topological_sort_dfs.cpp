#include <bits/stdc++.h>
using namespace std;
vector<list<int>> adj;
void topo(int n, bool *visited,stack<int>&st)
{
    visited[n] = true;
    for (auto i : adj[n])
    {
          if(!visited[i])  topo(i, visited,st);
    }
    st.push(n);
}
int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    bool visited[n];
    memset(visited, false, sizeof(visited));
    stack<int> st;// we will use stack and push the element postly after all the neighbours has been processed
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topo(i, visited,st);
        }
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}
