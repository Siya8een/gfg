//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find

int findFloor(std::vector<long long>& v, long long n, long long x) {
    std::sort(v.begin(), v.end());

    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] <= x) {
            // Check if the next element is greater than x
            // or if mid is already the last index
            if (mid == v.size() - 1 || v[mid + 1] > x) {
                return mid;
            } else {
                left = mid + 1;
            }
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends