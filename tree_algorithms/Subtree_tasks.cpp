#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll timer=0;

void eluer(vector<vector<ll>> &adj,vector<pair<ll,ll>> &sten , ll x,vector<bool> &visited)
{
    visited[x]=true;
    sten[x].first=timer++;
    for(auto i:adj[x])
    {
        if(!visited[i])
        {
            eluer(adj,sten,i,visited);
        }
    }
    sten[x].second=timer;
}

// -------- Segment Tree --------

void build_seg(ll idx, ll l, ll r, vector<ll> &seg, vector<ll> &flat)
{
    if(l == r)
    {
        seg[idx] = flat[l];
        return;
    }
    ll m = (l + r) / 2;
    build_seg(2*idx, l, m, seg, flat);
    build_seg(2*idx+1, m+1, r, seg, flat);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

void update_seg(ll idx, ll l, ll r, ll pos, ll val, vector<ll> &seg)
{
    if(l == r)
    {
        seg[idx] = val;
        return;
    }
    ll m = (l + r) / 2;
    if(pos <= m) update_seg(2*idx, l, m, pos, val, seg);
    else update_seg(2*idx+1, m+1, r, pos, val, seg);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

ll query_seg(ll idx, ll l, ll r, ll ql, ll qr, vector<ll> &seg)
{
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return seg[idx];
    ll m = (l + r) / 2;
    return query_seg(2*idx, l, m, ql, qr, seg)
         + query_seg(2*idx+1, m+1, r, ql, qr, seg);
}

int main() {
	ll n,q;
	cin>>n>>q;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	vector<vector<ll>> adj(n+1);
	for(ll i=0;i<n-1;i++)
	{
	    ll x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	
	vector<pair<ll,ll>> sten(n+1,{0,0});
	vector<bool> visited(n+1,false);
	timer=0;
	eluer(adj,sten,1,visited);

	// -------- Flatten Tree using Euler --------
	vector<ll> flat(n);
	for(ll i=1;i<=n;i++)
	{
	    flat[ sten[i].first ] = a[i-1];
	}

	// -------- Build Segment Tree --------
	vector<ll> seg(4*n, 0);
	build_seg(1, 0, n-1, seg, flat);
	
	while(q--)
	{
	    ll type;
	    cin>>type;
	    if(type==1)
	    {
	        ll x,y;
	        cin>>x>>y;
	        update_seg(1, 0, n-1, sten[x].first, y, seg);
	        a[x-1] = y;
	    }
	    else{
	        ll x;
	        cin>>x;
	        cout << query_seg(1, 0, n-1, sten[x].first, sten[x].second - 1, seg) << endl;
	    }
	}
}
