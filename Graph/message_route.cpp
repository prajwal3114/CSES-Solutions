#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v64 vector<ll>
#define v32 vector<int>
#define p64 pair<ll,ll>
#define p32 pair<int,int>
#define vv64 vector<vector<ll>>
#define vv32 vector<vector<int>>
#define p1 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
#define p2 priority_queue<ll>
#define c(y) cout<<"yes\n"
#define c(n) cout<<"no\n"
#define print cout<<"\n"
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define take32(a,n) for(int i=0;i<n;i++)cin>>a[i];
#define take64(a,n) for(ll i=0;i<n;i++)cin>>a[i];
#define forn(i,n) for(int i=0;i<n;i++)
 
ll gcd(ll a,ll b){while(b){a%=b;swap(a,b);}return a;}
 
int binary_search(v32 &arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
 
v32 sieve(int n) {
    v32 primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}
 
v64 dijkstra(int n, vector<vector<pair<ll, ll>>> &adj, int src) {
    v64 dist(n, LLONG_MAX);
    dist[src] = 0;
    p1 pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d_u = pq.top().first;
        pq.pop();
        if (d_u != dist[u]) continue;
        for (auto &v : adj[u]) {
            ll neighbor = v.first;
            ll weight = v.second;
            if (dist[u] + weight < dist[neighbor]) {
                dist[neighbor] = dist[u] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}
 
ll prim(int n, vector<vector<pair<ll,ll>>> &adj) {
    v64 key(n, LLONG_MAX);
    vector<bool> mst(n, false);
    key[0] = 0;
    p1 pq;
    pq.push({0, 0});
    ll res = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (mst[u]) continue;
        mst[u] = true;
        res += key[u];
        for (auto &v : adj[u]) {
            if (!mst[v.first] && v.second < key[v.first]) {
                key[v.first] = v.second;
                pq.push({key[v.first], v.first});
            }
        }
    }
    return res;
}
 
void dfs(int node, vv32& adj, vector<bool>& vis) {
    vis[node] = true;
    for (auto& nei : adj[node]) {
        if (!vis[nei]) dfs(nei, adj, vis);
    }
}
 
void bfs(int start, vv32& adj) {
    vector<bool> vis(adj.size(), false);
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (!vis[node]) {
            vis[node] = true;
            for (auto& nei : adj[node]) {
                if (!vis[nei]) q.push(nei);
            }
        }
    }
}
 
v32 topo_sort(int n, vv32& adj) {
    v32 indegree(n, 0), res;
    forn(i,n)for(auto& u:adj[i])indegree[u]++;
    queue<int> q;
    forn(i,n)if(indegree[i]==0)q.push(i);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto& u : adj[node]) {
            indegree[u]--;
            if (indegree[u] == 0) q.push(u);
        }
    }
    return res;
}
 
void dfsrec(vector<bool> &visited,vector<ll> &a,ll i,ll n){
    visited[i]=true;
    for(ll j=0;j<n;j++){
        if((!visited[j] && a[i]>a[j] && j>i) || (!visited[j] && a[i]<a[j] && j<i)){
            dfsrec(visited,a,j,n);
        }
    }
   
}
void dfsrec(vector<vector<ll>> &a,vector<bool> &visited,ll i){
    visited[i]=true;
    for(auto x:a[i]){
        if(!visited[x]){
            dfsrec(a,visited,x);
        }
    }
    return;
}
bool found = false;  // Global flag to track if a path is found
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1);
    
    // Input adjacency list
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
 
    // BFS setup
    queue<ll> q;
    vector<bool> visited(n + 1, false);
    vector<ll> parent(n + 1, -1); // Stores the parent of each node for path reconstruction
    
    q.push(1);
    visited[1] = true;
 
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
 
        if (x == n) break;  // Exit early if destination is reached
 
        for (auto z : a[x]) {
            if (!visited[z]) {
                visited[z] = true;
                parent[z] = x;
                q.push(z);
            }
        }
    }
 
    // If no path exists
    if (parent[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    // Reconstruct the path
    vector<ll> path;
    for (ll v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
 
    // Output result
    cout << path.size() << "\n";
    for (ll v : path) cout << v << " ";
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;
    while (t--) solve();
    return 0;
}