//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

class Solution {
public:
    int tour(petrolPump p[], int n) {
        int start = 0;  // Starting point of the tour
        int balance = 0;  // Total petrol available at the current point
        int totalBalance = 0;  // Total petrol available at all the pumps

        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            totalBalance += p[i].petrol - p[i].distance;

            // If the balance becomes negative, the current starting point is not valid.
            // Move to the next petrol pump and reset the balance and starting point.
            if (balance < 0) {
                balance = 0;
                start = i + 1;
            }
        }

        // If the total petrol available at all pumps is greater than or equal to the total distance,
        // then a valid starting point exists. Return the starting point index.
        return (totalBalance >= 0) ? start : -1;
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends