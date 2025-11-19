#include <bits/stdc++.h>
using namespace std;
#define ll long long 
 
void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    vector<ll> dp(x+1,0);
    for(ll i=0;i<n;i++){
        for(ll j=x;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
        }
    }
    cout<<dp[x]<<endl;
}
int main() {
	// your code goes here
	ll t;
    t=1;
	while(t--)
	{
	    solve();
	}
 
}