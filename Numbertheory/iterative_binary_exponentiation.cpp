#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

int main()
{
    int a, b; // Declare variables a and b
    cin >> a >> b; // Input values for a and b from the user

    int ans = 1; // Initialize the answer to 1
    while (b > 0) // Loop until b becomes 0
    {
        if (b & 1) // If b is odd
        {
            ans = ans * a; // Multiply ans by a
            b -= 1; // Decrement b by 1 to make it even
        }
        a = a * a; // Square the value of a
        b = b >> 1; // Right shift b by 1 (equivalent to dividing by 2)
    }
    cout << ans; // Output the final answer
}