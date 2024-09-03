//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
       unordered_map<int, int> mpp;

        // Insert all positive elements into the map.
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                mpp[arr[i]]++;
            }
        }

        // Find the smallest missing positive number.
        for (int i = 1; i <= n; i++) {
            if (mpp.find(i) == mpp.end()) {
                return i;
            }
        }

        // If no number is missing from 1 to n, return n + 1.
        return n + 1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends