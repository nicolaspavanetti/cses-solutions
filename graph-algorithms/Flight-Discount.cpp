#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dijkstra(
    vector<vector<pair<ll,ll>>>& graph,
    ll source,
    vector<ll>& price
)
{
    priority_queue
    <
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        greater<pair<ll,ll>>
    > pq;

    pq.push({0, source});
    price[source] = 0;

    while(!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if(price[u] != w) continue;

        for(auto [v, p] : graph[u])
        {
            if(price[u] + p < price[v])
            {
                price[v] = price[u] + p;
                pq.push({price[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> graph(n + 1);
    vector<vector<pair<ll,ll>>> reverse_graph(n + 1);

    // We keep all edges so that we can try the discount
    // on every single edge later.
    vector<tuple<ll,ll,ll>> edges;

    for(int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        reverse_graph[b].push_back({a, c});

        edges.push_back({a, b, c});
    }

    // Shortest distance from 1 to every vertex
    vector<ll> dist1(n + 1, LLONG_MAX);
    dijkstra(graph, 1, dist1);

    // Shortest distance from every vertex to n
    vector<ll> distn(n + 1, LLONG_MAX);
    dijkstra(reverse_graph, n, distn);

    ll answer = LLONG_MAX;

    // Try putting the discount on every edge
    for(auto [u, v, w] : edges)
    {
        ll current = dist1[u] + w / 2 + distn[v];

        answer = min(answer, current);
    }

    cout << answer << '\n';
}
