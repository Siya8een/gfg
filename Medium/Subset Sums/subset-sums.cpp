//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void recursion(int i, vector<int>& arr, int n, vector<int>& ans, int sum) {
        // Base case: if we've considered all elements
        if (i == n) {
            ans.push_back(sum);
            return;
        }
        
        // Include the current element in the sum
        recursion(i + 1, arr, n, ans, sum + arr[i]);
        
        // Exclude the current element from the sum
        recursion(i + 1, arr, n, ans, sum);
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        recursion(0, arr, n, ans, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends