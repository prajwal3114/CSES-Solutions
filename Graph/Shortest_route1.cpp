#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v64 vector<ll>
#define p64 pair<ll, ll>
#define vv64 vector<vector<p64>>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
vector<ll> dijkstra(ll n, vv64 &adj) {
    vector<ll> dist(n + 1, LLONG_MAX);
    priority_queue<p64, vector<p64>, greater<p64>> pq;
    
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    
    while (!pq.empty()) {
        ll d = pq.top().first, u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (size_t i = 0; i < adj[u].size(); i++) {
            ll v = adj[u][i].first, w = adj[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    return dist;
}
 
void solve() {
    ll n, m;
    cin >> n >> m;
    
    vv64 adj(n + 1);
    
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));  // One-way edge
    }
    
    v64 ans = dijkstra(n, adj);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    fast_io;
    solve();
    return 0;
}
