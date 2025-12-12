#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll startNode = -1;
bool dfs(vector<vector<ll>> &a, ll i, vector<int> &state, vector<ll> &path) {
    state[i] = 1; // visiting
    path.push_back(i);
 
    for (auto x : a[i]) {
        if (state[x] == 0) {
            if (dfs(a, x, state, path)) return true;
        }
        else if (state[x] == 1) {
            startNode = x;
            path.push_back(x);
            return true; // found cycle
        }
    }
 
    path.pop_back();
    state[i] = 2; // finished
    return false;
}
 
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1);
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
 
    vector<int> state(n + 1, 0);
    vector<ll> path;
    bool found = false;
 
    for (ll i = 1; i <= n; i++) {
        if (state[i] == 0) {
            if (dfs(a, i, state, path)) {
                found = true;
                break;
            }
        }
    }
 
    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    // Extract only the cycle part
    auto it = find(path.begin(), path.end(), startNode);
    vector<ll> cycle(it, path.end());
 
    cout << cycle.size() << "\n";
    for (auto x : cycle) cout << x << " ";
}