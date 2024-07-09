//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int ans = 1e7;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        for(int i=1;i<n-1;i++){
            int l = i-1,r=i+1;
            while(l>=0 && r < n){
                int sum = arr[l] + arr[r] + arr[i];
                if(abs(sum - target) < abs(ans - target)){
                    ans = sum;
                }
                else if(abs(sum - target) == abs(ans - target))
                    ans = max(ans, sum);
                if(sum > target)
                    l--;
                else 
                    r++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends