//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   
    
      long long int merge(long long int &inv, vector<long long> &arr, int lowi, int mid, int high) {
        long long temp[high - lowi + 1];
        int i = lowi, j = mid + 1, k = 0;

        // Merge two sorted subarrays while counting inversions
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // All elements from arr[i] to arr[mid] will form inversions with arr[j]
                inv += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }

        // Copy remaining elements from left half
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements from right half
        while (j <= high) {
            temp[k++] = arr[j++];
        }

        // Copy back the merged array into the original array
        for (i = lowi; i <= high; i++) {
            arr[i] = temp[i - lowi];
        }

        return inv;
    }

    
    long long int merge_sort ( long long int & inv, vector<long long> &arr , int low , int high){
        if ( low == high){
             return 0;
        }
        int mid = low + ( high-low)/2;
       merge_sort( inv, arr, low, mid);
     merge_sort( inv, arr, mid+1 , high);
      merge( inv, arr , low , mid , high);
         
         return inv;
        
        
    }
    long long int inversionCount(vector<long long> &arr) {
        // Your Code Here
        //int inversions =0;
         long long int inv =0;
       int n = arr.size();
          merge_sort (inv ,arr, 0 , n-1);
          return inv;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends