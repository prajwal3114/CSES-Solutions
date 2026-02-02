#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<ll> a, seg;
 
void build(ll idx, ll l, ll r)
{
    if(l==r)
    {
        seg[idx]=a[l];
        return;
    }
    ll m=(l+r)/2;
    build(2*idx,l,m);
    build(2*idx+1,m+1,r);
    seg[idx]=min(seg[2*idx],seg[2*idx+1]);
}
 
ll solve(ll idx, ll l, ll r, ll ql, ll qr)
{
    if(qr<l || r<ql) return LLONG_MAX;
    if(ql<=l && r<=qr) return seg[idx];
    ll m=(l+r)/2;
    return min(
        solve(2*idx,l,m,ql,qr),
        solve(2*idx+1,m+1,r,ql,qr)
    );
}
 
int main()
{
    ll n,q;
    cin>>n>>q;
    a.resize(n);
    seg.resize(4*n);
    for(ll i=0;i<n;i++) cin>>a[i];
 
    build(1,0,n-1);
 
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<solve(1,0,n-1,x-1,y-1)<<endl;
    }
}
