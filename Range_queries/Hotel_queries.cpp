#include <bits/stdc++.h>
using namespace std;
#define ll long long 
 
vector<ll> seg, h;
 
ll get(ll idx, ll l, ll r, ll v)
{
    if(seg[idx] < v) return -1;
    if(l == r) return l;
    ll m = (l + r) / 2;
    if(seg[2*idx] >= v) return get(2*idx, l, m, v);
    return get(2*idx+1, m+1, r, v);
}
 
void upd(ll idx, ll l, ll r, ll pos, ll val)
{
    if(l == r)
    {
        seg[idx] = val;
        return;
    }
    ll m = (l + r) / 2;
    if(pos <= m) upd(2*idx, l, m, pos, val);
    else upd(2*idx+1, m+1, r, pos, val);
    seg[idx] = max(seg[2*idx], seg[2*idx+1]);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,m;
    cin>>n>>m;
    h.resize(n);
    for(ll i=0;i<n;i++) cin>>h[i];
 
    seg.assign(4*n,0);
    for(ll i=0;i<n;i++) upd(1,0,n-1,i,h[i]);
 
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        ll pos = get(1,0,n-1,x);
        if(pos == -1)
        {
            cout<<0<<" ";
        }
        else{
            cout<<pos+1<<" ";
            h[pos] -= x;
            upd(1,0,n-1,pos,h[pos]);
        }
    }
    cout<<endl;
}