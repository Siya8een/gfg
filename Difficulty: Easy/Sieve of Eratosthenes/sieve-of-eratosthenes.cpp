//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
          vector<int> ans;
        vector<bool> prime(N + 1, true);  // Mark all numbers as prime initially

        prime[0] = prime[1] = false;  // 0 and 1 are not prime

        for (int i = 2; i * i <= N; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    prime[j] = false;  // Mark multiples of i as non-prime
                }
            }
        }

        // Collect all prime numbers
        for (int i = 2; i <= N; i++) {
            if (prime[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends