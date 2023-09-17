//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void  dfs ( int a, vector <int>& ans , int vis[], int V , vector <int> adj[]){
        vis[a]= 1;
        ans.push_back (a);
        for ( auto it : adj[a]){
             if (!vis[it])
            dfs ( it, ans, vis , V, adj );
        }
         
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
         int start =0; 
          int vis[V]= {0};
         
          vector <int > ans ;
           dfs( start, ans, vis , V, adj );
            return ans ;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends