#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    bool visited = false;
    vector <int> path;
    vector<int> parent(n+1,0);
    queue <int> q;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    q.push(1);
    int x;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (x==n)
        {
            visited = true;
            break;
        }

        for(int neighborn:graph[x])
        {
            if(parent[neighborn]==0)
            {
                parent[neighborn] = x;
                q.push(neighborn);
            }
        }
    }
    int couter = 2;
    if(visited)
    {
        x = parent[n];
        path.push_back(n);
        while(x!=1)
        {
            couter++;
            path.push_back(x);
            x = parent[x];
        }
        path.push_back(x);
        cout<<couter<<'\n';
        for(int i=couter-1;i>=0;i--)
        {
            cout<<path[i]<<" ";
        }
    }
    else cout<<"IMPOSSIBLE";
}