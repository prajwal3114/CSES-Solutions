#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    sort(a.begin(), a.end()); // Sorting the array
 
    long long count = 1; // Initialize with 1 as the first element is always counted
    for (long long i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            count++;
        }
    }
 
    cout << count << endl;
    return 0;
}