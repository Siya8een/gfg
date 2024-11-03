//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    constexpr static int INF = 1000000000 +9;
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        // vector <vector < int>> adjlist(mat.size());
        // for( int i=0; i < mat.size(); i++){
        //     for( int j =0; j < mat[0].size(); j++){
        //         int u =i;
        //         int v = j;
        //         int dist = mat[i][j];
        //         adjlist[u].push_back( dist);
        //         adjlist[v].push_back(dist);
        //     }
        // }
        int V = mat.size();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (mat[i][j] == -1 && i != j) {
                    mat[i][j] = INF;
                }
            }
        }

        // Apply Floyd-Warshall algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (mat[i][k] != INF && mat[k][j] != INF) { // Ensure no overflow by checking INF
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (mat[i][j] == INF) {
                    mat[i][j] = -1;
                }
            }
        }
        // to detect neg cycle
        // for( int i=0; i< mat.size(); i++){
        //     for( int j =0; j < mat[0].size(); j++){
        //      for( int via =0; via < mat.size(); via++){
        //          if( mat[i][j] < (mat[i][via] + mat[via][j])){
        //          return {-1};
        //           } 
                 
        //      }   
        // }
        // }
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends