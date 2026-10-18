#include <bits/stdc++.h>
#include <iterator>
using namespace std;

typedef long long ll;
int main()
{
    /*Im doing by brutal force, this isn't good*/
    ll x,n;
    cin>>x>>n;
    set<ll> resp = {0,x};
    multiset<ll>final = {x};
    ll val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        auto it = resp.insert(val).first;
        ll ant = *prev(it);
        ll pos = *next(it);
        final.erase(final.find(pos-ant));
        final.insert(val-ant);
        final.insert(pos-val);
        cout<<*final.rbegin()<<" ";
    }
}