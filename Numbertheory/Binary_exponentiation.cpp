#include<bits/stdc++.h>
using namespace std;
long long power(long long a,long long b){
    if(b==1) return a;
    if(b==0){
        return 1;
    }
    long long x=power(a,b/2);
    if(b%2!=0){
        return a*x*x;
    }
    return x*x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a,b;
    cin>>a>>b;
    cout<<power(a,b)<<" ";
    cout<<pow(a,b);
}