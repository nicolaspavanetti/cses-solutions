#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n; 
    cin>>n;
    int a,b, sum =0,maxim=0 ;
    multiset <array<int,2>> costumers;
    for(int i=0; i<n;i++)
    {
        cin>>a>>b;
        costumers.insert({a,0});
        costumers.insert({b,1});
    }
    for (auto arr:costumers)
    {
        if (arr[1]==0)
        {
            sum++;
            maxim = max(maxim,sum);
        }
        else sum--;
    }
    cout<<maxim;
}
