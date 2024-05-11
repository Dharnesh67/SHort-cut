bool printsubsequencesWithsumk(vector<int> &v, int i, int n, int k, int sum, vector<int> &ans)
{
    if (i >= n)
    {
        if (sum == k)
        {
            for (int x : ans)
                cout << x << " ";
            cout << endl;
        }
        return sum == k;
    }
    if (sum > k)
    {
        return false;
    }
    if (sum == k)
    {
        for (int x : ans)
            cout << x << " ";
        cout << endl;
        return true;
    }
    ans.push_back(v[i]);
    bool take =printsubsequencesWithsumk(v, i + 1, n, k, sum + v[i], ans);
    if(take) return true;
    ans.pop_back();
    bool notake=printsubsequencesWithsumk(v, i + 1, n, k, sum, ans);
    if(notake) return true;
}
