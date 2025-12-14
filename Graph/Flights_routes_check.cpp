#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void dfs(vector<vector<ll>> &g, vector<bool> &vis, ll u) {
    vis[u] = true;
    for (ll v : g[u]) {
        if (!vis[v]) {
            dfs(g, vis, v);
        }
    }
}
 
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);       // original graph
    vector<vector<ll>> rg(n + 1);      // reversed graph
 
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);     // edge from x -> y
        rg[y].push_back(x);    // reversed edge y -> x
    }
 
    vector<bool> vis(n + 1, false);
    dfs(g, vis, 1);
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << "1 " << i << endl;
            return 0;
        }
    }
 
    fill(vis.begin(), vis.end(), false);
    dfs(rg, vis, 1);
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << i << " 1" << endl;
            return 0;
        }
    }
 
    cout << "YES\n";
    return 0;
}