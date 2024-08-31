//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> left_smaller(n, -1), right_larger(n, -1);
        stack<int> st;
        st.push(-1);
        
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && st.top() >= arr[i]) st.pop();
            if(!st.empty()) left_smaller[i] = st.top();
            st.push(arr[i]);
        }
        
        stack<int> s;
        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && s.top() <= arr[i]) s.pop();
            if(!s.empty()) right_larger[i] = s.top();
            s.push(arr[i]);
        }
        
        
        for(int i = 0; i < n; ++i) {
            if(left_smaller[i] == -1 || right_larger[i] == -1) continue;
            int a = left_smaller[i];
            int b = right_larger[i];
            return {a, arr[i], b};
        }
        
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends