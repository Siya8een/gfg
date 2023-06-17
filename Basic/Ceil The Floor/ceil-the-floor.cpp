//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort ( arr, arr+n);
    int left = 0;
    int right = n - 1;
    int ceil = -1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            floor = arr[mid];
            ceil = arr[mid];
            break;
        } else if (arr[mid] < x) {
            left = mid + 1;
            ceil = arr[mid];
        } else {
            right = mid - 1;
            floor = arr[mid];
        }
    }

    return make_pair(ceil, floor);
}