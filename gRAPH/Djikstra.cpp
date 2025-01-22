#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pp pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define mii map<int, int>
#define msi map<string, int>
#define mci map<char, int>
#define si set<int>
#define sc set<char>
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define pb push_back
#define mod 1000000007

ll dj(int src, int n, vvll &graph, vll &curse, int target)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // Min-heap
    vll mp(n, LLONG_MAX), vis(n, -1);
    pq.push({0, src});
    mp[src] = 0;
    while (!pq.empty())
    {
        pp curr = pq.top(); // Extracting the minimum-weight node from the priority queue
        pq.pop();
        if (vis[curr.second] != -1)
            continue; // Marking the current node as visited
        vis[curr.second] = 1;
        for (auto neigh : graph[curr.second])
        {
            if (curse[neigh] != 1 && vis[neigh] == -1 && mp[neigh] > curr.first + 1)
            {
                mp[neigh] = curr.first + 1;  // Updating minimum weight for the node
                pq.push({mp[neigh], neigh}); // Adding neighbors to the priority queue
            }
        }
    }
    if (mp[target] == LLONG_MAX)
    {
        return -1;
    }
    return mp[target];
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll src, target;
    cin >> src >> target;
    vll curse(n);
    f(i, 0, n)
    {
        ll x;
        cin >> x;
        curse[i] = x;
    }
    vvll graph(n);
    f(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    ll result = dj(src, n, graph, curse, target);
    cout << result << "\n"; // Output the result
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
