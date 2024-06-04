#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    for (int i = 5; i >=0; i--)
    {
        cout<<((n&(1<<i))!=0); // this can use for check if the ith bit is set or not
        
    }
}
