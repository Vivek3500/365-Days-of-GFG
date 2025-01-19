//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int longestUniqueSubstr(string &s) {
        unordered_map<char, int> mp;
        
        int ans = 0;
        int n = s.size();
        int last = -1;
        for (int i = 0; i < n; i++){
            // cout << last << " " << i << endl;
            if (mp.find(s[i]) != mp.end()){
                last = max(last, mp[s[i]]);
            }
            ans = max(ans, i - last);
            mp[s[i]] = i;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends