#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
struct SegTree {
    ll n;
    vector<ll> seg;
 
    SegTree(ll n) : n(n) {
        seg.assign(4*n, 0);
    }
 
    void build(ll idx, ll l, ll r) {
        if(l == r) {
            seg[idx] = 1;
            return;
        }
        ll m = (l + r) >> 1;
        build(idx<<1, l, m);
        build(idx<<1|1, m+1, r);
        seg[idx] = seg[idx<<1] + seg[idx<<1|1];
    }
 
    ll first_ge(ll idx, ll l, ll r, ll x) {
        if(l == r) return l;
        ll m = (l + r) >> 1;
        if(seg[idx<<1] >= x) return first_ge(idx<<1, l, m, x);
        return first_ge(idx<<1|1, m+1, r, x - seg[idx<<1]);
    }
 
    void update(ll idx, ll l, ll r, ll pos) {
        if(l == r) {
            seg[idx] = 0;
            return;
        }
        ll m = (l + r) >> 1;
        if(pos <= m) update(idx<<1, l, m, pos);
        else update(idx<<1|1, m+1, r, pos);
        seg[idx] = seg[idx<<1] + seg[idx<<1|1];
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    vector<ll> a(n), p(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> p[i];
 
    SegTree st(n);
    st.build(1, 0, n-1);
 
    for(ll i = 0; i < n; i++) {
        ll pos = st.first_ge(1, 0, n-1, p[i]);
        cout << a[pos] << " ";
        st.update(1, 0, n-1, pos);
    }
    cout << "\n";
}
