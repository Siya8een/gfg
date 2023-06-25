//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack)
{
    int midIndex = (sizeOfStack - 1) / 2;

    stack<int> tempStack;

    // Pop and store elements from the original stack until the middle index
    if (sizeOfStack %2 ==0){
    for (int i = 0; i <= midIndex; i++) {
        tempStack.push(s.top());
        s.pop();
    }
}

if (sizeOfStack %2 ==1){
    for (int i = 0; i < midIndex; i++) {
        tempStack.push(s.top());
        s.pop();
    }
}
    // Skip the middle element by popping it from the original stack
    s.pop();

    // Push back the elements from the temporary stack to the original stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends