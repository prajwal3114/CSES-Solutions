#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pll pair<ll, ll>
#define INF 1e18
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, m;
    cin >> n >> m;
 
    vector<vector<pll>> g(n + 1), rg(n + 1); // g = original, rg = reversed
    vector<tuple<ll, ll, ll>> edges;
 
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        rg[v].emplace_back(u, w); // reverse edge
        edges.emplace_back(u, v, w);
    }
 
    auto dijkstra = [&](int start, vector<vector<pll>> &graph) {
        vector<ll> dist(n + 1, INF);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
 
        dist[start] = 0;
        pq.push({0, start});
 
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
 
            for (auto &[v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
 
        return dist;
    };
 
    vector<ll> dist1 = dijkstra(1, g);   // From source
    vector<ll> dist2 = dijkstra(n, rg);  // To destination
 
    ll ans = INF;
 
    for (auto &[u, v, w] : edges) {
        if (dist1[u] < INF && dist2[v] < INF) {
            ans = min(ans, dist1[u] + w / 2 + dist2[v]);
        }
    }
 
    cout << ans << '\n';
    return 0;
}