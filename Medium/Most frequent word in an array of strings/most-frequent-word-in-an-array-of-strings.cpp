//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
         unordered_map<string , int> freq;
         unordered_map< string ,int > occurrence;
         
         int k=1;
         for ( int i=0; i< n;i++){
             if ( occurrence.count( arr[i]) >0){
                 continue;
             }
            
                     occurrence[arr[i]] = k++;
           
         }
         int maxx = INT_MIN;
         string result ;
         for ( int i=0; i<n;i++){
              freq[arr[i]]++;
              if (maxx <= freq[arr[i]]) {
                 if ( maxx < freq[arr[i]]){
                      maxx = freq[arr[i]];
                       result = arr[i];
                 }
                  else {
                      if (occurrence[result]
                        < occurrence[arr[i]]) {
                        maxx= freq[arr[i]];
                        result = arr[i];
                    }
                  }
             }
         }
          return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends