#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll MOD = 1e9+7;
 
void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
 
    // bottom-up DP: dp[s] = number of ways to make sum s (combinations)
    vector<ll> dp(x+1,0);
    dp[0]=1;
 
    for(ll i=0;i<n;i++){
        for(ll s=a[i]; s<=x; s++){
            dp[s] = (dp[s] + dp[s - a[i]]) % MOD;
        }
    }
 
    cout<<dp[x]%MOD<<endl;
}
 
int main() {
    ll t;
    t=1;
    while(t--)
    {
        solve();
    }
}