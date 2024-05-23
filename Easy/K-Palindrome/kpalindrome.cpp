//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
        int kPalindrome(string str, int n, int k) {
            string s1 = str;
            reverse(str.begin(), str.end());
            string s2 = str;
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
            int lcs_length = LCS(s1, s2, n, n, dp);
            int min_insertions = n - lcs_length;
            
            return min_insertions <= k;
        }
        int LCS(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp) {
            for (int i = 1; i <= n1; ++i) {
                for (int j = 1; j <= n2; ++j) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[n1][n2];
        }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends