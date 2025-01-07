//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
         int n = arr.size();
        if(n<2) return {};
       
        int closestDiff = INT_MAX;
        int maxAbsDiff = -1;
        vector<int> result;
        int left = 0, right = n - 1;
        while (left < right) {
        int a = arr[left];
        int b = arr[right];
        int currentSum = a + b;
        int currentDiff = abs(currentSum - target);
        if (currentDiff < closestDiff || (currentDiff == closestDiff && abs(b - a) > maxAbsDiff)) {
            closestDiff = currentDiff;
            maxAbsDiff = abs(b - a);
            result = {a, b};
        }
        if (currentSum < target) {
            ++left;
        } else {
            --right;
        }
    }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends