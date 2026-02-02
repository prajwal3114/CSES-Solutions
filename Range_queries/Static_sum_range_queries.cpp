#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	// your code goes here
	ll n,q;
	cin>>n>>q;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	vector<ll> pre(n+1,0);
	for(ll i=0;i<n;i++)
	{
	    pre[i+1]=pre[i]+a[i];
	}
	while(q--)
	{
	    ll x,y;
	    cin>>x>>y;
	    cout<<pre[y]-pre[x-1]<<endl;
	    
	}
 
}
