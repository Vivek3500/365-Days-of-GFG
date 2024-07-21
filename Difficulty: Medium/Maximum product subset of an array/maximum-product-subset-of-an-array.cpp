//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            // Only 1 element in the array.
            return arr[0];
        }

        long long int ans = 1;
        int mod = 1e9 + 7;
        int id = -1, minElement = 0;
        int zeroCount = 0, negCount = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                // Counting number of zeros.
                zeroCount++;
            } else if (arr[i] < 0) {
                // Counting number of negative numbers.
                negCount++;
                if (id == -1 || arr[i] > minElement) {
                    // Storing the index of negative element having least magnitude.
                    id = i;
                    minElement = arr[i];
                }
            }
        }
        if (zeroCount == n) {
            // If there are all zeros.
            return 0;
        }
        if (negCount == 1 && zeroCount == n - 1) {
            // If all elements are zero except one negative element, then return 0.
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                continue;
            }
            if (negCount % 2 == 1 && i == id) {
                // Removing the negative element having least magnitude.
                continue;
            }
            ans = ((ans * arr[i]) % mod + mod) % mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends