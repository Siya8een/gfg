//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      vector<vector<pair<int, int>>> adjlist(V);
        
        for (int u = 0; u < V; ++u) {
            for (auto it : adj[u]) {
                int v = it[0];
                int wt = it[1];
                adjlist[u].push_back({v, wt});
                adjlist[v].push_back({u, wt}); // Assuming an undirected graph
            }
        }

        // Priority queue to select the edge with the minimum weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // To keep track of vertices included in the MST
        vector<bool> inMST(V, false);

        // Start with the first vertex (assuming vertex 0 as the starting point)
        pq.push({0, 0}); // (weight, vertex)
        int mstCost = 0;

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with the smallest key value
            int weight = pq.top().first;
            pq.pop();

            if (inMST[u]) continue; // If this vertex is already included in MST, skip it

            inMST[u] = true; // Include this vertex in MST
            mstCost += weight; // Add the edge weight to the total cost

            // Traverse all adjacent vertices of u
            for (auto it : adjlist[u]) {
                int v = it.first;
                int wt = it.second;

                if (!inMST[v]) {
                    pq.push({wt, v});
                }
            }
        }

        return mstCost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends