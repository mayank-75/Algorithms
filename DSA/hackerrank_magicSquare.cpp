#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v[8] = 
{
    {
        {8,3,4}, {1,5,9}, {6,7,2}
    },

    {
        {4,3,8}, {9,5,1}, {2,7,6}
    },

    {
        {6,7,2}, {1,5,9}, {8,3,4}
    },

    {
        {8,1,6}, {3,5,7}, {4,9,2}
    },

    {
        {2,9,4}, {7,5,3}, {6,1,8}
    },

    {
        {4,9,2}, {3,5,7}, {8,1,6}
    },

    {
        {6,1,8}, {7,5,3}, {2,9,4}
    },

    {
        {2,7,6}, {9,5,1}, {4,3,8}
    }
};

int minsChange(vector<vector<int>> &v, vector<vector<int>> &s)
{
    int ans = 0 ;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //cout<<s[i][j]<<" "<<v[i][j]<<" " ;
            //cout<<abs(s[i][j]-v[i][j])<<endl ;
            ans += abs(s[i][j]-v[i][j]);
        }
    }
    //cout<<ans<<endl ;
    //cout<<endl ;
    return ans ;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {

    int ans = INT_MAX ;
    for(int i=0;i<8;i++)
    {
        ans = min(ans,minsChange(v[i],s)) ;
    }

    return ans ;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
