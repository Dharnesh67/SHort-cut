void printsubsequences(vector<int>&v,int i,vector<int>&ans,int n){
        if(i>=n) {
            for(int x:ans) cout<<x<<" ";
            cout<<endl;
            return;
        }
        ans.push_back(v[i]);
        printsubsequences(v,i+1,ans,n);
        ans.pop_back();
        printsubsequences(v,i+1,ans,n);
}
