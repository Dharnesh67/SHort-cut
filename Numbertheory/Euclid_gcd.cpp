#include <bits/stdc++.h>
using namespace std;

int gcd(int num1,int num2) //num1<num2 always
{
    int rem=num2%num1;
    if(rem==0){
        return num1;
    }
    return gcd(rem,num1);
}
int main()
{
    cout<<gcd(12,30);
}