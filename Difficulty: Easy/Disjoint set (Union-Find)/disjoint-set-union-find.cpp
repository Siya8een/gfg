//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends


/*Complete the functions below*/
int find(int A[],int X)
{
       //add code here
       if (A[X] == X) {
        return X; // X is the representative of its set
    }
    // Path compression
    return A[X] = find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
	int rootX = find(A, X); // Find the root of X
    int rootZ = find(A, Z); // Find the root of Z

    if (rootX != rootZ) {
        // Merge the sets by making one root point to the other
        A[rootX] = rootZ; // You can also use rank/size for optimization
    }
}