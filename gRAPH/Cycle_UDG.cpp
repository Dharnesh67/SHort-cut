#include<bits/stdc++.h>
using namespace std;
int find(vector<int>&par,int a){
    return par[a]=(par[a]==a)? a:find(par,par[a]);
}
bool Union(vector<int>&par,vector<int>&rank,int a,int b){
    a=find(par,a);
    b=find(par,b);
    if(a==b) return true;
    if(rank[a]>rank[b]){
        par[b]=a;
        rank[a]++;
    }
    else{
        par[a]=b;
        rank[b]++;
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>par(n+1);
    vector<int>rank(n+1,0);
    for (int i = 0; i <=n; i++)
    {
        par[i]=i;
    }
    while (m--)
    {
        int x,y;
        cin>>x>>y;
        bool b=Union(par,rank,x,y);
        if(b==1){
            cout<<"CYCLE DETECTED";
            break;
        }
    }
    return 0;
}
