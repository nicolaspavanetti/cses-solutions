#include <bits/stdc++.h>
using namespace std;

typedef long long  int ll;
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
    }

    vector<ll> dist(n + 1, INT64_MAX);
    dist[1] = 0;

    priority_queue<
        pair<ll, ll>,
        vector<pair<ll, ll>>,
        greater<pair<ll, ll>>
    > pq;

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto [v, w] : graph[u]) {

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}