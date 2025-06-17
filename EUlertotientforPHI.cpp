#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e6 + 1;
vector<ll> phi(maxn);

void compute_totients() {
    for (int i = 0; i < maxn; ++i) phi[i] = i;
    for (int i = 2; i < maxn; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < maxn; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    compute_totients();

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << phi[x] << "\n";
    }
    return 0;
}
