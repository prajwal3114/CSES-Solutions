#include <bits/stdc++.h>
using namespace std;
 
struct BIT {
    int n;
    vector<long long> b;
 
    BIT(int n) {
        this->n = n;
        b.assign(n + 1, 0);
    }
 
    void add(int i, long long v) {
        while (i <= n) {
            b[i] += v;
            i += i & -i;
        }
    }
 
    long long sum(int i) {
        long long s = 0;
        while (i > 0) {
            s += b[i];
            i -= i & -i;
        }
        return s;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
 
    BIT bit(n);
 
    // Read initial array and build difference array
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    for (int i = 1; i <= n; i++) {
        bit.add(i, a[i]);
        bit.add(i + 1, -a[i]);
    }
 
    while (q--) {
        int t;
        cin >> t;
 
        if (t == 1) {
            int l, r;
            long long u;
            cin >> l >> r >> u;
            bit.add(l, u);
            bit.add(r + 1, -u);
        } else {
            int k;
            cin >> k;
            cout << bit.sum(k) << '\n';
        }
    }
 
    return 0;
}
