//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Templ
class Solution {
public:
    void Reverse(stack<int> &St) {
        vector<int> ans;
        
        // Transfer elements from stack to vector
        while (!St.empty()) {
            ans.push_back(St.top());
            St.pop();
        }
        
        // Reverse the vector
        // Transfer elements back from vector to stack
        for (int i = 0; i < ans.size(); i++) {
            St.push(ans[i]);
        }
    }
};


//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends