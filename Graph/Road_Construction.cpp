#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> visited(n + 1, 0);
    vector<ll> thiscom(n + 1, -1);
    vector<unordered_set<ll>> s(n + 1); // one set per component id
    ll largest = 1;
    ll count = 0;
    ll total = n;
 
    while (m--) {
        ll x, y;
        cin >> x >> y;
 
        if (visited[x] && visited[y]) {
            if (thiscom[x] == thiscom[y]) {
                cout << total << " " << largest << endl;
            } else {
                total -= 1;
                ll cx = thiscom[x], cy = thiscom[y];
                // merge components cy into cx
                if (s[cx].size() < s[cy].size()) swap(cx, cy);
                for (auto node : s[cy]) {
                    s[cx].insert(node);
                    thiscom[node] = cx;
                }
                s[cy].clear();
                largest = max(largest, (ll)s[cx].size());
                cout << total << " " << largest << endl;
            }
            continue;
        }
        else if (!visited[x] && !visited[y]) {
            total -= 1;
            s[count].insert(x);
            s[count].insert(y);
            thiscom[x] = count;
            thiscom[y] = count;
            visited[x] = visited[y] = 1;
            largest = max(largest, (ll)s[count].size());
            count++;
        }
        else {
            if (visited[x]) {
                total -= 1;
                ll cx = thiscom[x];
                s[cx].insert(y);
                thiscom[y] = cx;
                visited[y] = 1;
                largest = max(largest, (ll)s[cx].size());
            } else {
                total -= 1;
                ll cy = thiscom[y];
                s[cy].insert(x);
                thiscom[x] = cy;
                visited[x] = 1;
                largest = max(largest, (ll)s[cy].size());
            }
        }
        cout << total << " " << largest << endl;
    }
}