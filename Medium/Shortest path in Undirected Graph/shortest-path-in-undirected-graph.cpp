//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Create an adjacency list
        vector<vector<int>> adj(N);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Vector to store the shortest path distance from the source
        vector<int> shortest(N, INT_MAX);
        shortest[src] = 0;

        // Queue for BFS
        queue<int> q;
        q.push(src);

        // BFS traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (shortest[neighbor] == INT_MAX) {
                    shortest[neighbor] = shortest[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Replace INT_MAX with -1 for unreachable nodes
        for (int i = 0; i < N; i++) {
            if (shortest[i] == INT_MAX) {
                shortest[i] = -1;
            }
        }

        return shortest;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends