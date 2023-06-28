//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    if (n==0){
	        return 0;
	    }
	    if (n==1){
	        return 2;
	    }
	    
	    int endone=1;
	    int endzero=1;
	    int ans = endone+ endzero ;
	    int i=2;
	    while (i<= n){
	       int x = endzero% 1000000007;
	        endzero= endone+ endzero % 1000000007;
	        endone = x% 1000000007;
	        ans = endone + endzero% 1000000007;
	        i++;
	    }
	    return ans% 1000000007;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends