#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<vector<int>> adj;
 
pair<int,int> bfs(int start) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest = start;
 
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if(dist[v] > dist[farthest]) {
                    farthest = v;
                }
            }
        }
    }
    return {farthest, dist[farthest]};
}
 
vector<int> bfs_all(int start) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    // Step 1: find one end of diameter
    auto u = bfs(1).first;
    // Step 2: find the other end of diameter
    auto v = bfs(u).first;
    // Step 3: distances from u and v
    vector<int> dist_u = bfs_all(u);
    vector<int> dist_v = bfs_all(v);
 
    // Step 4: answer for each node
    for(int i=1;i<=n;i++) {
        cout << max(dist_u[i], dist_v[i]) << " ";
    }
    cout << "\n";
}