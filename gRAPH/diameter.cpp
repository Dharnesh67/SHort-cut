 int diameter(map<int,vector<int>>& g) {
        int dia = 0;
        int farthnode = -1;
        queue<int> q;
        q.push(0);
        int level = 0;
        set<int>vis;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto x = q.front();
                q.pop();
                if (vis.count(x))
                    continue;
                farthnode = x;
                vis.insert(x);
                for (auto& neigh : g[x]) {
                    q.push(neigh);
                }
            }
            level++;
        }
        cout<<farthnode<<endl;
        q.push(farthnode);
        vis.clear();
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto x = q.front();
                q.pop();
                if (vis.count(x))
                    continue;
                farthnode = x;
                vis.insert(x);
                for (auto& neigh : g[x]) {
                    q.push(neigh);
                }
            }
            dia++;
        }
        return dia;
    }
