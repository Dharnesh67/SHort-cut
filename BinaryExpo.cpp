ll BinaryExpo(ll a, ll b)
{
    if(b==0) return 1;
    cout<<b<<" ";
    if(b%2!=0){
        return a*BinaryExpo(a,b/2)*BinaryExpo(a,b/2);
    }
    return BinaryExpo(a,b/2)*BinaryExpo(a,b/2);
}
