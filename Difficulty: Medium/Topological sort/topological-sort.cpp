//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	// radhey radhey nmah sidham om shanti jai shree krishna
	
	void dfs( int i , vector < int > & vis , vector < int > adj[], stack < int >& q){
	    vis[i] = 1;
	   
	    for ( auto it : adj[i]){
	         if ( vis[it]==0){
	              dfs( it , vis , adj , q);
	         }
	    }
	     q.push(i);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector < int > ans ;
	    if ( V == 0){
	        return ans;
	    }
	    vector < int > vis ( V , 0);
	    stack < int > q;
	    for ( int i =0 ; i < V ; i++){
	         if ( vis[i]==0){
	              dfs ( i , vis , adj , q);
	         }
	    }
	    
	    while ( !q.empty()){
	        ans.push_back( q.top());
	        q.pop();
	    }
	    
	    return ans ;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends