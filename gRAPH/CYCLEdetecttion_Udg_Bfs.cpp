
class Solution // GFG
{
public:
    bool f(vector<int> adj[], int node, vector<bool> &vis)
    {
        queue<pair<int, int>> q; // node, par
        q.push({node, -1});
        vis[node] = true;
        while (!q.empty())
        {
            auto n = q.front();
            q.pop();
            for (int &x : adj[n.first])
            {

                if (!vis[x])
                {
                    q.push({x, n.first});
                     vis[x] = true;
                }
                else if(x!=n.second) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // vector<int>par(V);
        vector<bool> vis(V, false);
        // int par=-1;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && f(adj, i, vis))
            {
                return true;
            }
        }
        return false;
    }
};
