//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        unordered_map <int, int> mpp ;
        int sum =0;
        int max_length = -1;
        mpp[0] ++;
        for( int i =0; i < arr.size(); i++){
            sum += arr[i];
              if (sum == k) {
                max_length = i + 1;
            }
            
            // If `sum - k` is found, calculate the subarray length
            if (mpp.find(sum - k) != mpp.end()) {
                max_length = max(max_length, i - mpp[sum - k]);
            }
            
            // Store `sum` in map only if it hasn't been stored before
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }
        return max_length;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends