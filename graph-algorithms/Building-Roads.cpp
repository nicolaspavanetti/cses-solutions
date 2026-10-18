#include <bits/stdc++.h>
using namespace std;

void exploring(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& end, int node)
{
    if(visited[node-1]) return;
    visited[node-1]=true;
    end.push(node);
    for (int neighborns:graph[node])
    {
        exploring(graph, visited, end, neighborns);
    }
}

int main()
{
    int n,m,a,b,counter = 0;
    cin>>n>>m;
    vector <vector<int>> graph(n+1);
    vector<bool> visited(n,false);
    vector<array<int,2>> answer;
    stack <int> end;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    exploring(graph, visited, end, 1);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            counter++;
            answer.push_back({end.top(),i+1});
            exploring(graph,visited,end,i+1);
        }
    }
    if(counter==0) cout<<0;
    else{
        cout<<counter<<'\n';
        for(array arr:answer)
        {
            cout<<arr[0]<<" "<< arr[1]<<'\n';
        }

    }
}