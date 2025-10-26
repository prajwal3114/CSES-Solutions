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
int lower_bound_custom(vector<ll>& arr, ll x) {
    int l = 0, r = arr.size() - 1, ans = arr.size();
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            ans = mid; // Update answer
            r = mid - 1; // Move to the left part
        } else {
            l = mid + 1; // Move to the right part
        }
    }
    return ans; // Index of the lower bound
}
const ll inf=1e18,mod=998244353,ofs=500000;
void sortByLength(vector<string> &v) {
    sort(v.begin(), v.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
}
void sortPairs(vector<pair<float, ll>> &v) {
    sort(v.begin(), v.end(), [](const pair<float, ll> &a, const pair<float, ll> &b) {
        if (a.first == b.first) return a.second < b.second; // Sort second element in increasing order
        return a.first > b.first; // Sort first element in non-increasing order
    });
}
// bool dfsrec(vector<vector<ll>> &a, vector<bool> &visited, ll i, unordered_set<ll> &s, vector<ll> &ans) {
//     if (s.find(i) != s.end()) {
//         cout<<"worker"<<endl;
//         ans.push_back(i);
//         return true;
//     }
 
//     visited[i] = true;
//     s.insert(i);
//     ans.push_back(i);
 
//     for (auto x : a[i]) {
//         if (!visited[x]) {
//             cout<<
//             if (dfsrec(a, visited, x, s, ans)) {
//                 return true;
//             }
//         }
//     }
 
//     s.erase(i);
//     ans.pop_back();
//     return false;
// }
void solve() {
    // Input handling
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1); // Adjacency list for the graph (1-based indexing)
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
 
    // DFS to find a cycle
    vector<bool> visited(n + 1, false);
    vector<ll> ans;
    unordered_set<ll> s;
    bool cycleFound = false;
 
    function<bool(ll, ll)> dfsrec = [&](ll node, ll parent) -> bool {
        visited[node] = true;
        s.insert(node);
        ans.push_back(node);
 
        for (auto neighbor : a[node]) {
            if (!visited[neighbor]) {
                if (dfsrec(neighbor, node)) {
                    return true;
                }
            } else if (neighbor != parent && s.find(neighbor) != s.end()) {
                // Cycle detected
                ans.push_back(neighbor);
                return true;
            }
        }
 
        s.erase(node);
        ans.pop_back();
        return false;
    };
 
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfsrec(i, -1)) {
                cycleFound = true;
                break;
            }
        }
    }
 
    if (!cycleFound) {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    // Extract the cycle from the ans vector
    ll last = ans.back();
    ll cycleStart = 0;
    for (ll i = 0; i < ans.size() - 1; i++) {
        if (ans[i] == last) {
            cycleStart = i;
            break;
        }
    }
 
    // Output the cycle
    cout << ans.size() - cycleStart << "\n";
    for (ll i = cycleStart; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main() {
    fast_io;
    int t;
    t=1;
    
    while (t--) solve();
    return 0;
}