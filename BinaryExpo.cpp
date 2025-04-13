ll BinaryExpo(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = BinaryExpo(a, b / 2);
    res = (res * res) % mod;
    if (b % 2 != 0) {
        res = (res * a) % mod;
    }
    return res;
}
