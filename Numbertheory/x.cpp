#include <iostream>
using namespace std;

const long long mod = 1e18;
int largest(int n) {
    for (int i = 2; i*i <= n; i++) { 
        if (n % i == 0) {
            if (n/i == i)
                return i;
            else
                return n / i;
        }
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 2; ; i++) {
            int x = i * n;
            int y = largest(x);
            if (y != n) {
                break; 
            }
            sum += x;
            sum %= mod; 
        }
        cout << sum << endl;
    }
    return 0;
}