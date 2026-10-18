#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;

    const ll INF = 4e18;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    for (ll i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (ll i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;

        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
    }

    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        if (dist[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << dist[a][b] << '\n';
    }
}