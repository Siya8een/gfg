//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void printStringNTimes(const std::string& str, int n) {
    if (n <= 0) {
        return;
    }
    
    std::cout << str << std::endl;
    printStringNTimes(str, n - 1);
}


  void printSquare(int n) {
    std::string str(n, '*');
    std::string spacedStr;
    
    // Add spaces between each asterisk
    for (int i = 0; i < str.size(); i++) {
        spacedStr += str[i];
        if (i != str.size() - 1) {
            spacedStr += ' ';
        }
    }
    
    printStringNTimes(spacedStr, n);
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends