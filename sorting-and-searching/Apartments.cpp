#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, m, k, sum = 0;
    cin >> n >> m >> k;

    vector<ll> apart(n);
    vector<ll> desire(m);

    for (ll i = 0; i < n; i++)
        cin >> apart[i];

    for (ll i = 0; i < m; i++)
        cin >> desire[i];

    sort(apart.begin(), apart.end());
    sort(desire.begin(), desire.end());

    ll i = 0;
    ll j = 0;

    while (i < n && j < m)
    {
        if (apart[i] < desire[j] - k)
        {
            i++;
        }
        else if (apart[i] > desire[j] + k)
        {
            j++;
        }
        else
        {
            sum++;
            i++;
            j++;
        }
    }

    cout << sum;
}