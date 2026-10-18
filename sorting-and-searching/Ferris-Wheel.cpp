#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n, x, r=0;
    cin>>n>>x;
    vector <ll> kids;
    for(int i=0;i<n;i++)
    {
        cin>>r;
        kids.push_back(r);
    }
    r=0;
    sort(kids.begin(),kids.end());
    int left=0, right = kids.size()-1;
    while(left<=right)
    {
        if(kids[left]+kids[right]<=x)
        {
            left++;
            r++;
        }
        else if(kids[right]<=x)
        {
            r++;
        }
        right--;
        
    }
    cout<<r;
}