//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int atmost (int k,string str){
        int i = 0;
        int j = 0;
        int cnt =0;
        unordered_map<char , int> mpp;
        while ( j < str.size() ){
            mpp[str[j]]++;
            while(mpp.size() > k){
                mpp[str[i]]--;
                if( mpp[str[i]] == 0){
                    mpp.erase(str[i]);
                }
                i++;
               
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }
    int countSubstr(string str, int k) {
        // code here.
        return  atmost(k, str) - atmost(k-1, str) ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends