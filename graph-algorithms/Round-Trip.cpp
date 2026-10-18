#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> parent;
vector<int> cycle;

bool dfs(int u, int p)
{
    visited[u] = 1;

    for (int v : graph[u])
    {
        // Don't immediately go back through the edge we came from
        if (v == p)
            continue;

        // v hasn't been visited yet
        if (!visited[v])
        {
            parent[v] = u;

            if (dfs(v, u))
                return true;
        }
        else
        {
            // We found a cycle
            cycle.push_back(v);

            int cur = u;

            while (cur != v)
            {
                cycle.push_back(cur);
                cur = parent[cur];
            }

            cycle.push_back(v);

            return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, 0);
    parent.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                cout << cycle.size() << '\n';

                for (int x : cycle)
                    cout << x << ' ';

                cout << '\n';

                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}