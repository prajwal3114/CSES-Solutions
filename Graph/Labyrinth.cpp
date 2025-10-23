#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v64 vector<ll>
#define v32 vector<int>
#define p64 pair<ll,ll>
#define vv32 vector<vector<int>>
#define vv64 vector<vector<ll>>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') start = {i, j};
            if (a[i][j] == 'B') end = {i, j};
        }
    }
 
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<char> dirSymbols = {'R', 'D', 'L', 'U'};
 
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
 
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;
 
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
 
                if (make_pair(nx, ny) == end) {
                    // Found the endpoint, trace the path
                    string path;
                    pair<int, int> curr = end;
                    while (curr != start) {
                        auto [px, py] = parent[curr.first][curr.second];
                        for (int j = 0; j < 4; j++) {
                            if (px + directions[j].first == curr.first && py + directions[j].second == curr.second) {
                                path += dirSymbols[j];
                                break;
                            }
                        }
                        curr = parent[curr.first][curr.second];
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES\n" << dist[end.first][end.second] << "\n" << path << "\n";
                    return;
                }
            }
        }
    }
 
    cout << "NO\n";
}
 
int main() {
    fast_io;
    int t = 1;
    while (t--) solve();
    return 0;
}