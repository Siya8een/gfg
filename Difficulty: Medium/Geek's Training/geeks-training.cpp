//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve( vector<vector< int >>& arr, int n, int prev, int i, vector <vector< int > >& dp){
        if(i < 0){
             return 0;
        }
        if ( dp[i][prev+1]!= -1){
             return dp[i][prev+1];
        }
        int ans =0;
        for ( int j =0; j <3; j++){
            if ( j != prev){
                ans = max( ans, arr[i][j] + solve(arr, n, j, i-1, dp));
            }
        }
        dp[i][prev+1] = ans;
        return dp[i][prev+1];
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector <vector< int > > dp(n, vector < int>(4, -1));
        return solve(arr, n, -1, n-1, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends