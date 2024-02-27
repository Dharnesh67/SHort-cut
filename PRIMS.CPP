#define pp pair<int, int>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<list<pp>> graph;

// Function to add an undirected edge with weight to the graph
void add_edge(int src, int des, int weight) {
    graph[src].push_back({weight, des});
    graph[des].push_back({weight, src});
}

// Function to perform Prim's algorithm and return the total weight of the minimum spanning tree
ll prims(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;  // Min heap priority queue of pairs
    unordered_map<int, int> mp;  // Map to store minimum weight for each node
    unordered_set<int> vis;  // Set to keep track of visited nodes
    vector<int> par(n + 1);  // Parent array to store the parent of each node in the MST
    
    // Initializing minimum weights to infinity
    for (int i = 1; i <= n; i++) {
        mp[i] = INT_MAX;
    }

    // Pushing the source node with weight 0 to start the algorithm
    pq.push({0, src});
    mp[src] = -1;  // Marking the source node as visited with weight -1

    int total_node = 0, ans = 0;

    // Main loop of Prim's algorithm
    while (!pq.empty() && total_node < n) {
        pp curr = pq.top();  // Extracting the minimum-weight node from the priority queue
        if (vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert(curr.second);  // Marking the current node as visited
        ans += curr.first;  // Adding the weight to the total MST weight
        total_node++;

        pq.pop();

        // Iterating through neighbors of the current node
        for (auto neigh : graph[curr.second]) {
            if (!vis.count(neigh.second) && mp[neigh.second] > neigh.first) {
                pq.push({neigh.first, neigh.second});  // Adding neighbors to the priority queue
                par[neigh.second] = curr.second;  // Updating parent information
                mp[neigh.second] = neigh.first;  // Updating minimum weight for the node
            }
        }
    }

    return ans;  // Returning the total weight of the minimum spanning tree
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1, list<pp>());

    // Reading edges and weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    int start;
    cin >> start;

    // Calling the Prim's algorithm function and printing the result
    cout << prims(start, n);

    return 0;
}
