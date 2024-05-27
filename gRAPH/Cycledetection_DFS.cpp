class Solution { // GFG
  public:
    bool dfs(int par,vector<int>adj[],int node,vector<bool>&vis){
       vis[node]=true;
       for(int &x:adj[node]){
           if(x==par) continue;
           if(vis[x]) return true;
            if(dfs(node,adj,x,vis)){
                   return true;}
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // vector<int>par(V);
        vector<bool>vis(V,false);
        // int par=-1;
        for(int i =0;i<V;i++){
            if(!vis[i] && dfs(-1,adj,i,vis)){
                return true;
            }
        }
        return false;
    }
};
