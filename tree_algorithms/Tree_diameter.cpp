#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
ll dfs(vector<vector<ll>> &adj, vector<bool> &visited, ll i, ll &ans) {
    visited[i] = true;
    vector<ll> check;
    
    for (auto x : adj[i]) {
        if (!visited[x]) {
            check.push_back(dfs(adj, visited, x, ans));
        }
    }
 
    if (check.empty()) return 1; // leaf node
    
    if (check.size() == 1) {
        ans = max(ans, check[0] + 1);
        return check[0] + 1;
    }
 
    sort(check.begin(), check.end(), greater<ll>());
    ans = max(ans, check[0] + check[1] + 1);
    return check[0] + 1;
}
 
int main() {
    ll n;
    cin >> n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n + 1, false);
    ll ans = 0;
    dfs(adj, visited, 1, ans);
    cout << ans-1 << endl;
}