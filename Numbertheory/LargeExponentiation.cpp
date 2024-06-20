#include <bits/stdc++.h>
using namespace std;
// a<=10^9 and b<=10^9 we use large exponentiation 
// a^b=a^(b/2)*a^(b/2) if b is even
// a^b=a*a^(b/2)*a^(b/2) if b is odd
// Time Complexity: O(log(b))
const int mod=1e9+7;
// lets calculate 2 ^1024 using large exponentiation
int binary_multiply(int a,int b){
    int res=0;
    while(b>0){
        if(b&1){
            res=(res+a)%mod;
        }
        a=(a+a)%mod;
        b=b>>1;
    }
    return res;

}
int large_exponentiation(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res=binary_multiply(res,a)%mod;
        }
        a=binary_multiply(a,a);
        b=b>>1;
    }
    return res;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<large_exponentiation(a,b)<<endl;
    cout<<pow(a,b);
    return 0;
}