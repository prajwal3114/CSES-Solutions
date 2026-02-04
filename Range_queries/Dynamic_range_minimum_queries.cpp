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
 
void update(ll idx, ll l, ll r, ll pos, ll val)
{
    if(l==r)
    {
        seg[idx]=val;
        return;
    }
    ll m=(l+r)/2;
    if(pos<=m) update(2*idx,l,m,pos,val);
    else update(2*idx+1,m+1,r,pos,val);
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
        ll type,x,y;
        cin>>type>>x>>y;
        if(type==1)
        {
            update(1,0,n-1,x-1,y);
        }
        else
        {
            cout<<solve(1,0,n-1,x-1,y-1)<<endl;
        }
    }
}
