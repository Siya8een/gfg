//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
   bool truee(int x, int y, vector<string>& visited, int n, vector<vector<int>>& m) {
    if (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && visited[x][y] == '0') {
        return true;
    } else {
        return false;
    }
}

void solve(vector<vector<int>>& m, vector<string>& ans, vector<string>& visited, string path, int one, int two, int n) {
    if (one == n - 1 && two == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[one][two] = '1';

    // D R L U
    int x = one + 1;
    int y = two;
    if (truee(x, y, visited, n, m)) {
        path.push_back('D');
        solve(m, ans, visited, path, x, y, n);
        path.pop_back();
    }

    x = one;
    y = two + 1;
    if (truee(x, y, visited, n, m)) {
        path.push_back('R');
        solve(m, ans, visited, path, x, y, n);
        path.pop_back();
    }

    x = one - 1;
    y = two;
    if (truee(x, y, visited, n, m)) {
        path.push_back('U');
        solve(m, ans, visited, path, x, y, n);
        path.pop_back();
    }

    x = one;
    y = two - 1;
    if (truee(x, y, visited, n, m)) {
        path.push_back('L');
        solve(m, ans, visited, path, x, y, n);
        path.pop_back();
    }

    visited[one][two] = '0';
}

vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    string path = "";

    vector<string> visited(n, string(n, '0'));

    int one = 0;
    int two = 0;

    if (m[0][0] == 0) {
        return ans;
    }

    solve(m, ans, visited, path, one, two, n);
    return ans;
}
};
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends