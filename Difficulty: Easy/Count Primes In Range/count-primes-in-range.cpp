//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



class Solution {
public:
    int countPrimes(int L, int R) {
        // Edge cases
        if (R < 2) return 0;
        if (L < 2) L = 2;
        
        // Sieve of Eratosthenes to mark non-prime numbers
        std::vector<bool> isPrime(R + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        for (int i = 2; i <= std::sqrt(R); ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= R; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count primes in the range [L, R]
        int count = 0;
        for (int i = L; i <= R; ++i) {
            if (isPrime[i]) {
                ++count;
            }
        }

        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Ends