#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    queue <int> q;
    bool possible=true;
    vector<int> team(n+1,0);
    vector <bool> visited(n+1,false);
    int a,b;
    for (int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int x;
    for(int i=1;i<=n && possible;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            team[i]=1;
            q.push(i);
            while (!q.empty())
            {
                x = q.front();
                q.pop();
                for(int neighbor:graph[x])
                {
                    if (team[neighbor] != team[x]) team[neighbor] = team[x]%2+1;    
                    else
                    {
                        possible = false;
                        break;
                    }
                    if (!visited[neighbor])
                    {
                        q.push(neighbor);
                    }
                    visited[neighbor]=true;
                }
            }
        }
    }
    if (possible)
    {
        for(int i=1;i<=n;i++) cout<< team[i]<<" ";
    }
    else cout<<"IMPOSSIBLE";    


}
