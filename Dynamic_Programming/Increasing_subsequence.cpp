#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	// your code goes here
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
	    cin>>a[i];
	}
	vector<ll> dp;
	for(ll i=0;i<n;i++){
	    auto it=lower_bound(dp.begin(),dp.end(),a[i]);
	    if(it==dp.end()){
	        dp.push_back(a[i]);
	    }
	    else{
	        *it=a[i];
	    }
	}
	cout<<dp.size()<<endl;
 
}