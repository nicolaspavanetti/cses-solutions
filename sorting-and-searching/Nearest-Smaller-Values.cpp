#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n; cin>>n;
    ll arr[n];
    ll resp[n];
    ll x, contador=0;
    stack <pair<ll,ll>> pilha;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        contador = 0;
        while (true)
        {
            if (pilha.empty())
            {
                resp[i]=0;
                break;
            }
            if (pilha.top().first<arr[i])
            {
                resp[i] = pilha.top().second;
                break;
            }
            pilha.pop();
            contador++;
        }
        pilha.push({arr[i],i+1});


    }
    for (ll number:resp)
    {
        cout<<number<<" ";
    }

}