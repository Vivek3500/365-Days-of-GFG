//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isValid(double maxDist, vector<int>& positions, int maxNewPoints) {
    int n = positions.size();
    int requiredNewPoints = 0;

    for (int i = 1; i < n; i++) {
        int distance = positions[i] - positions[i - 1];
        double numNewPoints = (double)distance / maxDist;
        requiredNewPoints += ((int)numNewPoints);
    }

    // Check if the number of required new points is within the allowed limit
    return requiredNewPoints <= maxNewPoints;
}

double findSmallestMaxDist(vector<int> &arr, int k) {
     int n = arr.size();
    double low = 0;
    double high = arr[n - 1] - arr[0];
    double result = high;

    // Sort the positions to ensure correct distance calculations
    sort(arr.begin(), arr.end());

    // Perform binary search to find the minimum possible maximum distance
    while (high - low > 1e-6) {
        double mid = low + (high - low) / 2;
        
        // Check if it's possible to place points such that the max distance is mid
        if (isValid(mid, arr, k)) {
            high = mid;
            result = mid;
        } else {
            low = mid;
        }
    }

    return result;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends