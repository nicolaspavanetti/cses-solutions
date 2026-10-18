#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n,x;
    cin>>n;
    set <ll> numbers;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        numbers.insert(x);
    }

    cout<<numbers.size();
}