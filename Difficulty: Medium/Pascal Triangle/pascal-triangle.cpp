//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    vector<vector<int>> pascal;

    void makeNxtRow()
    {
        int sz = pascal.size();
        vector<int> curr = pascal[sz - 1];
        int sr = curr.size();
        vector<int> ans;
        ans.push_back(1);
        for (int i = 1; i < sr; i++)
        {
            ans.push_back(curr[i] + curr[i - 1]);
        }
        ans.push_back(1);
        pascal.push_back(ans);
    }

    vector<int> nthRowOfPascalTriangle(int n)
    {
        // code here
        pascal.push_back({1});
        pascal.push_back({1, 1});
        int s = n;
        n -= 2;
        while (n > 0)
        {
            makeNxtRow();
            n--;
        }
        return pascal[s - 1];
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends