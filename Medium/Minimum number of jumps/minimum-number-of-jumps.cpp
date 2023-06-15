//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
public:
    int minJumps(int arr[], int n) {
        if (n <= 1) {
            return 0; // No jumps needed if there is only one element or no elements.
        }
        
        if (arr[0] == 0) {
            return -1; // If the first element is 0, it's not possible to reach the end.
        }
        
        int maxReach = arr[0]; // Maximum index that can be reached.
        int steps = arr[0]; // Number of steps remaining.
        int jumps = 1; // Number of jumps taken.
        
        for (int i = 1; i < n; i++) {
            if (i == n - 1) {
                return jumps; // Reached the end, return the number of jumps.
            }
            
            maxReach = max(maxReach, i + arr[i]); // Update the maximum reach.
            steps--; // Use one step.
            
            if (steps == 0) {
                if (i >= maxReach) {
                    return -1; // Cannot progress further.
                }
                
                steps = maxReach - i; // Take a jump to the maximum reachable index.
                jumps++; // Increment the number of jumps.
            }
        }
        
        return -1; // If the loop ends without reaching the end, return -1.
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends