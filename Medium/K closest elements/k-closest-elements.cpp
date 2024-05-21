//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> a, int n, int k, int x) {
        // code here
        
        int r = upper_bound(a.begin(), a.end(),x) - a.begin();
        int l = lower_bound(a.begin(), a.end(), x) - a.begin() - 1;
        vector<int>ans(k);
        int ptr = 0;
        while((l >= 0 || r < n) && ptr < k){
            int leftdiff = INT_MAX, rightdiff = INT_MAX;
            if(l >= 0)
                leftdiff = x - a[l];
            if(r < n)
                rightdiff = a[r] - x;
            
            if(rightdiff <= leftdiff)
                ans[ptr++] = a[r++];
            else
                ans[ptr++] = a[l--];
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends