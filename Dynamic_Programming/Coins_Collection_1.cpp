#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll n,x;
	cin>>n>>x;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
	    cin>>a[i];
	}
	ll mod=1e9 + 7;;
	vector<ll> dp(x+1,0);
	for(ll i=1;i<=x;i++){
	    ll sum=0;
	    bool present=false;
	    for(auto x:a){
	        if(i-x>0){
	            sum=(sum+dp[i-x])%mod;
	        }
	        if(x==i){
	            present=true;
	        }
	    }
	    if(present){
	        sum=(sum+1)%mod;
	    }
	    dp[i]=sum;
	}
	cout<<dp[x]<<endl;
 
}