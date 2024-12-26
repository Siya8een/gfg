//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
       int n = adj.size(); // Number of vertices
        vector<int> vis(n, 0); // Visited array
        
        // Iterate over all components of the graph
        for (int start = 0; start < n; ++start) {
            if (!vis[start]) {
                queue<pair<int, int>> q;
                q.push({start, -1}); // {current node, parent}
                vis[start] = 1;

                while (!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for (int neighbor : adj[node]) {
                        if (!vis[neighbor]) {
                            vis[neighbor] = 1;
                            q.push({neighbor, node});
                        } else if (neighbor != parent) {
                            // If neighbor is visited and not parent, cycle detected
                            return true;
                        }
                    }
                }
            }
        }
        return false; //
         }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends