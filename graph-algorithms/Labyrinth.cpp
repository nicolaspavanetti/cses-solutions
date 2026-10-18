#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> graph(n);

    int start_i, start_j;
    int end_i, end_j;

    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];

        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'A')
            {
                start_i = i;
                start_j = j;
            }

            if (graph[i][j] == 'B')
            {
                end_i = i;
                end_j = j;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // parent[i][j] = the cell from which we reached (i,j)
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1})
    );

    // direction[i][j] = the movement used to reach (i,j)
    vector<vector<char>> direction(n, vector<char>(m));

    queue<pair<int, int>> q;

    q.push({start_i, start_j});
    visited[start_i][start_j] = true;

    // Directions: down, up, right, left
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    char move[] = {'D', 'U', 'R', 'L'};

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            // Check if the new position is inside the grid
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            // Can't walk through walls or already visited cells
            if (graph[ni][nj] == '#')
                continue;

            if (visited[ni][nj])
                continue;

            // We reached (ni,nj) from (i,j)
            visited[ni][nj] = true;
            parent[ni][nj] = {i, j};
            direction[ni][nj] = move[k];

            q.push({ni, nj});
        }
    }

    // B was never reached
    if (!visited[end_i][end_j])
    {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct the path
    string path;

    int i = end_i;
    int j = end_j;

    while (i != start_i || j != start_j)
    {
        path.push_back(direction[i][j]);

        auto [pi, pj] = parent[i][j];

        i = pi;
        j = pj;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.length() << '\n';
    cout << path << '\n';

    return 0;
}