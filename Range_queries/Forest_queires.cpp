#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> p(n+1, vector<int>(n+1, 0));
 
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++) {
            int val = (s[j-1] == '*');
            p[i][j] = val + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
 
    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
 
        int ans = p[y2][x2]
                - p[y1-1][x2]
                - p[y2][x1-1]
                + p[y1-1][x1-1];
 
        cout << ans << '\n';
    }
    return 0;
}
