/* key point to learn from this question
- travelling forward and then backward in order to ensure the the criteria given is satisfied
*/

#include <bits/stdc++.h>
# define int long long
using namespace std;

int max(int a, int b)
{
    if(a > b) return a ;
    else return b ;
}

// Complete the candies function below.
long candies(int n, vector<int> a) {

    int candy[n] ;
    memset(candy,0,sizeof(candy)) ;
    candy[0] = 1 ;
    for(int i=1;i<n;i++)
    {
        if(a[i] > a[i-1]) candy[i] = 1+candy[i-1] ;
        else candy[i] = 1 ;
    }

    for(int i=n-1;i>0;i--)
    {
        if(a[i] < a[i-1] && candy[i] >= candy[i-1])
        {
            candy[i-1] = 1+ candy[i] ;
        }
    }

    int res = 0 ;
    for(int x : candy) res += x , cout<<x<<" " ;
    cout<<endl ;
    return res ;
    


}

int32_t main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
