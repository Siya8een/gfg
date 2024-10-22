//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve( int k, vector < int>& arr, int i, vector<int>& dp){
      if( i == arr.size()-1 ){
           return 0;
      }
      if ( dp[i]!= -1){
           return dp[i];
      }
      int ans = INT_MAX;
     
      for ( int ind = i+1; ind <= i+k && ind < arr.size(); ind++){
           int a = abs(arr[ind] - arr[i]) + solve( k, arr, ind, dp);
           ans = min( a, ans);
      }
      dp[i] = ans;
      return dp[i];
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector < int > dp( arr.size(), -1);
        return solve( k , arr, 0, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends