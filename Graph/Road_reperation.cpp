#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    
    for (ll i = 0; i < m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    
    vector<ll> visited(n + 1, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    
    ll ans = 0;
    ll count = 0;
    
    while (!pq.empty()) {
        ll x = pq.top().first;  // weight
        ll y = pq.top().second; // node
        pq.pop();
        
        if (visited[y]) continue;
        
        visited[y] = true;
        ans += x;
        count++;
        
        if (count == n) {
            cout << ans << endl;
            return 0;
        }
        
        for (auto f : adj[y]) {
            if (!visited[f.first]) {
                pq.push({f.second, f.first});
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}