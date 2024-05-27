ll kruskals(vector<edge> &input,int n,int e){ // number of vertices and edges
      sort(input.begin(),input.end(),cmp);
      vector<int>parent(n+1);
      vector<int>rank(n+1,1);
        for (int i = 0; i <=n; i++) { 
            parent[i]=i;
        }
        int edgecount=0;// ek tree me n-1 edges hoti h agar graph me n verctices h to 
        int i =0;
        ll ans=0;
        while (edgecount<n-1 and i<input.size()){
            edge curr =input[i];  // sorted so we will get the minimum wt edge
            int srcpar=find(parent,curr.src);
            int despar=find(parent,curr.des);
            if(srcpar!=despar){  // add edge this will not make cycle 
                Union(parent,rank,srcpar,despar);
                ans+=curr.weight;
                edgecount++;
            }
            i++;// jump to next edge  whether you picked or not the last edge
        }  


        return ans;    
}
