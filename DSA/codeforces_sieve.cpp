// question based on application of sieve

// quesiton is asking whether a number has 3distict factors or not

/* approach-
-simple we have to just find if a the square root of number 
is prime or not*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; ++i) cin >> arr[i];
    ll m = sqrt(*max_element(arr, arr+n));
    vector<bool> primes(m+1, true);
    primes[0] = primes[1] = false;
    for (ll i = 2; i <= m; ++i)
    {
        if (primes[i])
        {
            for (ll j = 2*i; j <= m; j += i)
                primes[j] = false;
        }
    }
    ll temp;
    for (ll x : arr)
    {
        temp = sqrt(x);
        if (primes[temp] && temp * temp == x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}