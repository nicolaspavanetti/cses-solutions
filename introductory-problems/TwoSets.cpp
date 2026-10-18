#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    int l1[n/2+1],l2[n/2];

    if (n%4==1 || n%4==2)
    {
        cout<<"NO";
    }
    else if (n%4==0)
    {
        l1[0]=1;
        l2[0]=2;
        for (int i=1;i<=n/4;i++)
        {
            l1[i] = l1[i-1]+2;
            l1[n/2-i] = n+1-l1[i-1];
            l2[i] = l2[i-1]+2;
            l2[n/2-i] = n+1-l2[i-1];
        }
        cout<<"YES"<<'\n';
        cout<<n/2<<'\n';
        for(int i=0;i<n/2;i++) cout<<l1[i]<<' ';
        cout<<'\n';
        cout<<n/2<<'\n';
        for(int i=0;i<n/2;i++) cout<<l2[i]<<' ';
    }
    else
    {
        l1[0]=1;
        l1[1]=2;
        l2[0]=3;
        for (int i=2;i<=n/4+1;i++)
        {
            l1[i] = l1[i-1]+2;
            l1[n/2-i+2] = n+l1[2]-l1[i];
            l2[i-1] = l2[i-2]+2;
            l2[n/2-i+1] = n+l1[2]-l2[i-1];
        }
        cout<<"YES"<<'\n';
        cout<<n/2+1<<'\n';
        for(int i=0;i<n/2+1;i++) cout<<l1[i]<<' ';
        cout<<'\n';
        cout<<n/2<<'\n';
        for(int i=0;i<n/2;i++) cout<<l2[i]<<' ';
    }
}