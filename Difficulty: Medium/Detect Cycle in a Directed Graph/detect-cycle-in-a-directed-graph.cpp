//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool solve(int V, vector<vector<int>>& adj, vector<int>& vis, int i ){
    vis[i] = 2;
    for( auto it : adj[i]){
        if(vis[it] == 0){
            solve(V, adj, vis, it);
        }
        if(vis[it] == 2){ 
            // to check path visited
            return true;
        }
    }
    vis[i] = 1;
    return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
       // directed graph 
       //dfs
       vector <int> vis(V);
       int i = 0;
       for(i = 0; i < V ; i++) {
           if(vis[i] != 1) {
                if(solve(V, adj, vis, i))return true;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends