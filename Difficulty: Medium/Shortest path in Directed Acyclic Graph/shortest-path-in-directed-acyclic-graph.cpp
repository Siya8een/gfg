//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
         vector<vector<pair<int, int>>> adjlist(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjlist[u].push_back({v, w});
        }

        // Dijkstra's algorithm
        vector<int> shortest(N, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // {distance, node}
        shortest[0] = 0;

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adjlist[node]) {
                int nextNode = it.first;
                int edgeWeight = it.second;

                if (dist + edgeWeight < shortest[nextNode]) {
                    shortest[nextNode] = dist + edgeWeight;
                    pq.push({shortest[nextNode], nextNode});
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends