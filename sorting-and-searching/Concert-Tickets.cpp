#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<ll> tickets;
    for (int i = 0; i < n; i++) {
        ll h; cin >> h;
        tickets.insert(h);
    }
    for (int i = 0; i < m; i++) {
        ll t; cin >> t;
        auto it = tickets.upper_bound(t); // first element > t
        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } else {
            --it; // largest element <= t
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}