//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long gcd (long long A , long long B ){
      while(B != 0){
          int temp = B;
          B = A%B;
          A= temp;
      }
      return A;
  }
  long long lcm (long long A , long long B ){
      return (A/ gcd(A,B))*B;
  }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector < long long > ans;
        long long a = lcm (A, B);
        long long b = gcd ( A, B);
        ans .push_back(a);
        ans.push_back(b);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends