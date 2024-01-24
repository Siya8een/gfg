//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/




// Define a static member function for comparison
static bool compare(Item a, Item b) {
    return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight);
}

class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sort items based on their value-to-weight ratio in descending order
        std::sort(arr, arr + n, compare);

        double ans = 0.0; // Initialize the result as a double

        // Loop through sorted items
        for (int i = 0; i < n; i++) {
            // If the current item's weight is less than or equal to the remaining capacity
            if (arr[i].weight <= W) {
                ans += arr[i].value; // Add the entire value of the current item
                W -= arr[i].weight;  // Update the remaining capacity
            } else {
                // If the current item's weight is greater than the remaining capacity
                ans += (arr[i].value * 1.0 / arr[i].weight) * W; // Add fraction of the value
                break; // Break the loop as the knapsack is full
            }
        }

        return ans;
    }
};




//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends