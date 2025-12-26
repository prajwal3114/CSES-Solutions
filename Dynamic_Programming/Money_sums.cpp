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
	set<ll> s;
	for(ll i=0;i<n;i++){
	    vector<ll> check;
	    for(auto x:s){
	        check.push_back(x+a[i]);
	    }
	    check.push_back(a[i]);
	    for(auto x:check){
	        s.insert(x);
	    }
	}
	cout<<s.size()<<endl;
	for(auto x:s){
	    cout<<x<<" ";
	}
	cout<<endl;
 
}
