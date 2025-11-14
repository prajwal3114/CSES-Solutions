#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod=1e9+7;
 
void solve()
{
   ll n;
   cin>>n;
   vector<vector<char>> grid(n,vector<char>(n));
   for(ll i=0;i<n;i++){
       for(ll j=0;j<n;j++){
           cin>>grid[i][j];
       }
   }
   vector<vector<ll>> dp(n,vector<ll> (n,0));
   if(grid[0][0]=='*' || grid[n-1][n-1]=='*'){
       cout<<0<<endl;
       return;
   }
   dp[0][0]=1;
   for(ll i=0;i<n;i++){
       for(ll j=0;j<n;j++){
           if(grid[i][j]!='*'){
               if(i+1<n && grid[i+1][j]!='*'){
               dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
           }
           if(j+1<n && grid[i][j+1]!='*'){
               dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
           }
           }
           
       }
   }
   cout<<dp[n-1][n-1]<<endl;
}
 
int main() {
	ll t;
	t=1;
	while(t--)
	{
	    solve();
	}
}
