//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
         vector < int > vis( V , -1);
        queue < pair<int , int> > q;
        for ( int i =0 ; i < V ; i++)
       { 
           if ( vis[i] == -1)
        {   q.push( { i , -1});
        // { node , parent }
        vis[i]=1;
        while ( !q.empty()){
            auto node= q.front().first;
            auto p= q.front().second;
            q.pop();
            for ( auto it : adj[node]){
                if ( vis[it]==-1){
                    vis[it]=1;
                   
                    q.push({ it , node});
                }
                else if(vis[it]== 1 && it != p)  {
                  // if (parent[it] != p){
                       return true;
                  // }
                }
            }
        }
           }
       }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends