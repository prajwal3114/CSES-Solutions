#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll mod=1000000007;
	ll sum=0;
	vector<ll> dp(n+1);
	dp[0]=1;
	for(ll i=1;i<=n;i++){
	      ll low=1;
	      while(low<=6 && i-low>=0){
	          dp[i]=(dp[i]+dp[i-low])%mod;
	          low++;
	      }
	}
    cout<<(dp[n])%mod<<endl;
}