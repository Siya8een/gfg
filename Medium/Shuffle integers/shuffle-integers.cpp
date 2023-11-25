//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:


void shuffleArray(int arr[], int n)
{
    std::vector<int> ans(n);
    int i = 0;
    int j = n / 2 ;
    int m = 0;

    while (i != n / 2 +1 && j != n) {
        if (m % 2 == 0) {
            ans[m] = arr[i];
            i++;
        } else {
            ans[m] = arr[j];
            j++;
        }
        m++;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }

    
	}
};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends