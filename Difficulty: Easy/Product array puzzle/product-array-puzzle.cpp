//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        // Allocate memory for product array andinitialise it by 1
        vector<long long int> vec(n, 1ll);
        if (n == 1) {
            return vec;
        }

        // In this loop temp will store the product of values on the left side of
        // nums[i]
        long long temp = 1ll;
        for (int i = 0; i < n; i++) {
            vec[i] *= temp;
            temp *= nums[i];
        }

        // In this loop temp will store the product of values on the right side of
        // nums[i]
        temp = 1ll;
        for (int i = n - 1; i >= 0; i--) {
            vec[i] *= temp;
            temp *= nums[i];
        }

        return vec; // return the expected vector
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends