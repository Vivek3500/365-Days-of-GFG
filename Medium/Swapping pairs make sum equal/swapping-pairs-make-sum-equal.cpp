//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  private:
    // Function to calculate the sum of an array.
    int getSum(int X[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += X[i];
        return sum;
    }

    // Function to calculate the target value.
    int getTarget(int A[], int n, int B[], int m) {
        int sum1 = getSum(A, n);
        int sum2 = getSum(B, m);

        if ((sum1 - sum2) % 2 != 0)
            return INT_MIN;
        return ((sum1 - sum2) / 2);
    }

  public:
    // Function to find if swapping values from both arrays can make their sums equal.
    int findSwapValues(int a[], int n, int b[], int m) {
        // Sorting both arrays.
        sort(a, a + n);
        sort(b, b + m);

        // Calculating the target value.
        int target = getTarget(a, n, b, m);

        // If target value is not feasible, return -1.
        if (target == INT_MIN)
            return -1;

        int i = 0, j = 0;

        // Iterating through both arrays to find the values that can be swapped.
        while (i < n && j < m) {
            int diff = a[i] - b[j];

            // If difference is equal to target, swapping is possible so return 1.
            if (diff == target) {
                return 1;
            }

            // If difference is less than target, increment index i.
            else if (diff < target)
                i++;

            // If difference is greater than target, increment index j.
            else
                j++;
        }

        // If no valid swap is found, return -1.
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends