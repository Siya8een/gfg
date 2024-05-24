//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& inStack) {
        visited[node] = 1;
        inStack[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, adj, visited, inStack))
                    return true;
            } else if (inStack[it])
                return true;
        }

        inStack[node] = 0;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> inStack(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, inStack))
                    return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends