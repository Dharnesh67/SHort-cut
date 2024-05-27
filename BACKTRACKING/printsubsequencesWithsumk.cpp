void printsubsequencesWithsumk(vector<int>&v,int i,int n,int k ,int sum,vector<int>&ans){
        if(i>=n) {
           if(sum==k) {for(int x:ans) cout<<x<<" ";
            cout<<endl;}
            return;
        }
        if(sum==k){
            for(int x:ans) cout<<x<<" ";
            cout<<endl;
            return;
        }
        ans.push_back(v[i]);
        printsubsequencesWithsumk(v,i+1,n,k,sum+v[i],ans);
        ans.pop_back();
        printsubsequencesWithsumk(v,i+1,n,k,sum,ans);
}
