//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
         unordered_map< char , int > mpp;
         for ( int i =0 ;i< str.length();i++){
            
             mpp [ str [i]]++;
         }
         int maxx = INT_MIN;
        
          char result = '0';
          for ( auto it : mpp){
              if (maxx< it.second||(maxx== it.second && it .first < result) ){
              maxx = max( maxx, it.second);
              result =it.first;
              }
          }
           return result;
          
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends