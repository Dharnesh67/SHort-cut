#include <bits/stdc++.h>
using namespace std;

int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    return gcd(num2, num1 % num2);
}

int main()
{
    int x=gcd(4,12);
    int lcm=(4*12)/x;
    cout<<lcm;
}