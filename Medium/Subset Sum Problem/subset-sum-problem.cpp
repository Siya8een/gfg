//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    bool solve(int i, vector<int>& arr, int sum, vector<vector<int>>& dp) {
        // Base cases
        if (sum == 0) {
            return true;
        }
        if (i == 0) {
            return (arr[0] == sum);
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

     
        // Recursive cases
        bool nottaken = solve(i - 1, arr, sum, dp);
        bool taken = false;
        if (arr[i] <= sum) {
            taken = solve(i - 1, arr, sum - arr[i], dp);
        }
        dp[i][sum] = nottaken || taken;

        return dp[i][sum];
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        // Initialize dp table with -1
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        // Call the solve function and return its result
        return solve(n - 1, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends