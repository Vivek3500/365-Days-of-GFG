//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int maxLen(vector<int> &arr) {
        // Your code here
        int res = 0;
        int n=arr.size();
        int sum[n+1];
        sum[0]=0;
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum[i+1]=(arr[i]==0?-1:1)+sum[i];
            mp[sum[i+1]]=(i+1);
        }
        for(int i=0;i<=n;i++){
            int f =sum[i];
            if(mp.find(f) != mp.end()){
                int len = mp[f]-i;
                res = len>res?len:res;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends