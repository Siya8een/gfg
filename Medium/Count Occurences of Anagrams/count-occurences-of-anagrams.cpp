//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    //{ Driver Code Starts
    bool allelement0(vector<int>& mpp) {
        for (int &i : mpp) { // Corrected the condition
            if (i != 0)
                return false;
        }
        return true;
    }

    int search(string pat, string txt) {
        // code here

        if (pat.length() > txt.length()) {
            return 0;
        }
        int result = 0;
        vector<int> mpp(26, 0);
        for (int i = 0; i < pat.length(); i++) {
            char ch = pat[i];
            mpp[ch - 'a']++;
        }
        int i = 0;
        int j = 0;
        while (j < txt.length()) {

            mpp[txt[j] - 'a']--;

            if (j - i + 1 == pat.length()) { // Corrected the condition
                if (allelement0(mpp)) {
                    result++;
                }
                mpp[txt[i] - 'a']++; // Corrected the character to be incremented
                i++;
            }

            j++;
        }
        return result;
    }
    //} Driver Code Ends
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// } Driver Code Ends