#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pll pair<ll, ll>
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m, k;
    cin >> n >> m >> k;
 
    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    priority_queue<pll, vector<pll>, greater<>> pq;
    vector<vector<ll>> dist(n + 1);  // Store up to k distances per node
 
    pq.push({0, 1}); // {distance, node}
 
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
 
        if (dist[u].size() >= k) continue;
        dist[u].push_back(d);
 
        for (auto [v, w] : adj[u]) {
            pq.push({d + w, v});
        }
    }
 
    for (ll d : dist[n]) {
        cout << d << " ";
    }
    cout << "\n";
 
    return 0;
}