//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int solve(int length, vector<int> &price, int i, vector<vector<int>> &dp) {
        // Base cases
        if (i == 0) {
            return length * price[0];
        }
        if (dp[i][length] != -1) { 
            return dp[i][length];
        }

        // Recursive calls
        int not_take = solve(length, price, i - 1, dp);
        int take = 0;
        if (length >= i + 1) { 
            take = price[i] + solve(length - (i + 1), price, i, dp);
        }

        dp[i][length] = max(not_take, take);
        return dp[i][length];
    }

    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n, price, n - 1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends