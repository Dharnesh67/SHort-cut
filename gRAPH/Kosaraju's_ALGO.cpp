#include <bits/stdc++.h> // strongly connected components
// strongly connected components is a group of vertices in a directed graph such that there is a path between every pair of vertices in the group.
using namespace std; // GFG QUESTION STRONGLY CONNECTED COMPONENT
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    stack<int> st;

    void topo(vector<bool> &vis, int node, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (int &x : adj[node])
        {
            if (!vis[x])
            {
                topo(vis, x, adj);
            }
        }
        st.push(node);
    }
    void dfs(vector<bool> &vis, int node, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (int &x : adj[node])
        {
            if (!vis[x])
            {
                dfs(vis, x, adj);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<bool> vis(V, 0);
        vector<vector<int>> adj1(V);
        for (int i = 0; i < V; i++)
        {
            for (int &x : adj[i])
            {
                adj1[x].push_back(i); // ab saare edges ko reverse kar do
            }
            if (vis[i])
            {
                continue;
            }
            topo(vis, i, adj); // /stack mei sare vertices aa gaye hai
        }
        int ans = 0;
        fill(begin(vis), end(vis), false);
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (!vis[top])
            {
                dfs(vis, top, adj1);
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    // 1. saare edges ko reverse kar do and uske baad dfs laga do
    // 2. jab dfs laga rahe ho toh uss vertex ko mark kar do
    // 3. jab dfs khatam ho jaye toh uss vertex ko stack mei push kar do topological order ke liye
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}