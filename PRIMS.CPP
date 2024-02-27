
ll prims(int src, int n)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> s; // visited
    vector<int> parent(n+1);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] =0;
    int total_count = 0;
    int result = 0;
    while (total_count < n  and !pq.empty())
    {    pp curr = pq.top();
        if (s.count(curr.second))
        {
            pq.pop();
            continue;
        }
        s.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();
        for (auto neighbour : grph[curr.second])
        {
            if (!s.count(neighbour.first) and mp[neighbour.first] > neighbour.second)
            {
                pq.push({neighbour.second, neighbour.first});
                parent[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
}
// function prims(src, numberOfNodes):
//     priorityQueue pq
//     visitedSet visited
//     parentArray parent
//     distanceMap distance

//     for node in 1 to numberOfNodes:
//         distance[node] = INFINITY
//     distance[src] = 0

//     pq.push({0, src})
    
//     totalNodes = 0
//     totalCost = 0

//     while totalNodes < numberOfNodes and not pq.isEmpty():
//         currentNode = pq.pop()

//         if visited.contains(currentNode):
//             continue

//         visited.insert(currentNode)
//         totalNodes += 1
//         totalCost += currentNode.cost

//         for neighbor in graph[currentNode.node]:
//             if not visited.contains(neighbor.node) and distance[neighbor.node] > neighbor.cost:
//                 pq.push({neighbor.cost, neighbor.node})
//                 parent[neighbor.node] = currentNode.node
//                 distance[neighbor.node] = neighbor.cost

//     return totalCost
