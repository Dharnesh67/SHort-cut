#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;
const int m = 1e9 + 7;

int main()
{
    int a, b; // Declare variables a and b
    cin >> a >> b; // Input values for a and b from the user

    long long ans = 1; // Initialize the answer to 1
    while (b > 0) // Loop until b becomes 0
    {
        if (b & 1) // If b is odd
        {
            ans = ((ans % m) *1LL* (a % m)) % m; // Multiply ans by a modulo m
        }
        a = (a *1LL* a) % m; // Square the value of a modulo m
        b  >>= 1; // Right shift b by 1 (equivalent to dividing by 2)
    }
    cout << ans << " "; // Output the final answer
}