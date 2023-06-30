//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s) {
    int64_t remainder = 0;

    for (char ch : s) {
        if (ch != '0' && ch != '1') {
            return false;
        }
        int64_t digit = ch - '0';

        remainder = (remainder * 2 + digit) % 3;
    }

    return remainder == 0;
	    
	}


};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends