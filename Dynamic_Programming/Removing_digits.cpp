#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll MOD=1e9+7;
 
ll rec(vector<ll> &dp,ll x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    ll y=x;
    ll ans=INT_MAX;
    while(y>0){
        ll digit=y%10;
        y/=10;
        if(digit>0){
            ans=min(ans,1+rec(dp,x-digit));
        }
    }
    dp[x]=ans;
    return dp[x];
}
 
void solve()
{
   ll n;
   cin>>n;
   vector<ll> dp(n+1,-1);
   cout<<rec(dp,n)<<endl;
}
 
int main() {
	ll t;
	t=1;
	while(t--)
	{
	    solve();
	}
}
