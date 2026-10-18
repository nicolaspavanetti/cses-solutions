#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    const ll INF = 1e9;
    vector<ll>dp(x+1,INF);
    dp[0]=0;
    for(ll i=1;i<=x;i++)
    {
        for(ll coin:coins)
        {
            if(i-coin>=0)
            {
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
    }
    if(dp[x]==INF) cout<<-1;
    else cout<<dp[x];
}