//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getMinDiff(std::vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;  // No height difference if there's only one element
        
        // Sort the array
        std::sort(arr.begin(), arr.end());

        // Initial difference without any adjustment
        int minDiff = arr[n-1] - arr[0];

        // Iterate through the sorted array and calculate the possible minimum difference
        for (int i = 1; i < n; ++i) {
            if (arr[i] < k) continue; // Skip if adjusting will make height negative

            // Adjust the minimum and maximum values after modification
            int minValue = std::min(arr[0] + k, arr[i] - k); // Adjust minimum height
            int maxValue = std::max(arr[n-1] - k, arr[i-1] + k); // Adjust maximum height

            // Update the minimum difference
            minDiff = std::min(minDiff, maxValue - minValue);
        }

        return minDiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends