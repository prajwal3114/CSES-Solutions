#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void dfs1(vector<vector<ll>> &a, vector<bool> &visited, ll i, vector<ll> &order) {
    visited[i] = true;
    for (auto x : a[i]) {
        if (!visited[x]) {
            dfs1(a, visited, x, order);
        }
    }
    order.push_back(i);  // finish time
}
 
void dfs2(vector<vector<ll>> &ar, vector<bool> &visited, ll i, vector<ll> &component, ll count) {
    visited[i] = true;
    component[i] = count;
    for (auto x : ar[i]) {
        if (!visited[x]) {
            dfs2(ar, visited, x, component, count);
        }
    }
}
 
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1), ar(n + 1);
 
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);    // original graph
        ar[y].push_back(x);   // reversed graph
    }
 
    vector<ll> order;
    vector<bool> visited(n + 1, false);
 
    // First DFS to get finishing times
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(a, visited, i, order);
        }
    }
 
    // Reset visited
    fill(visited.begin(), visited.end(), false);
    vector<ll> component(n + 1, 0);
    ll count = 0;
 
    // Process nodes in reverse finishing time
    reverse(order.begin(), order.end());
    for (ll i = 0; i < order.size(); i++) {
        if (!visited[order[i]]) {
            count++;
            dfs2(ar, visited, order[i], component, count);
        }
    }
 
    cout << count << "\n";  // Number of strongly connected components
    for (ll i = 1; i <= n; i++) {
        cout << component[i] << " ";  // Component number for each node
    }
    cout<<endl;
 
    return 0;
}