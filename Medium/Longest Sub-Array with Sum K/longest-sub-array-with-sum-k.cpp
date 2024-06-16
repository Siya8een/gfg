//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
      map<long long ,int> presum;
        int maxlength=0;
        int left=0;
        int right=N-1;
        int sum=0;
        
        for (int i =0; i<N; i++)
        {
            sum+=A[i];
            if(sum==K)
            {
                maxlength= max(i+1,maxlength);
            }
            
            int rem = sum -K;
            if(presum.find(rem)!=presum.end() && left<=right)
            {
                int len = i-presum[rem];
                maxlength=max(len,maxlength);
            }
            
            if(presum.find(sum)==presum.end())
            {
                presum[sum]=i;
            }
           
        }
        //   // Correct way to iterate and print the map
        // for (auto it = presum.begin(); it != presum.end(); ++it) {
        //     cout << "Key: " << it->first << ", Value: " << it->second << endl;
        // }
        return maxlength;
  // Complete the function
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends