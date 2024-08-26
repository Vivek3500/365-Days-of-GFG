//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if given pattern can match the given string.
    int wildCard(string pattern, string str) {
        bool isFirst = true;
        int trueVal = pattern.length();
        int dp[str.length() + 1][trueVal + 1];

        // Initializing the DP matrix with 0.
        memset(dp, 0, sizeof dp);

        // Setting the first cell to true, as both pattern and string are empty.
        dp[0][0] = true;

        // Initializing the first row for '*'.
        for (int i = 1; i <= pattern.length(); i++)
            if (pattern[i - 1] == '*')
                dp[0][i] = dp[0][i - 1];

        // Initializing the first cell of second row for '*'.
        if (trueVal > 0 and pattern[0] == '*')
            dp[0][1] = 1;

        // Filling the DP matrix row by row.
        for (int i = 1; i <= str.length(); i++) {
            for (int j = 1; j <= trueVal; j++) {
                // If pattern and string characters match or pattern has '?',
                // then update the current cell with the diagonal cell value.
                if (pattern[j - 1] == '?' or pattern[j - 1] == str[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                // If pattern has '*', update the current cell with the logical OR
                // of the cell above and the cell to the left.
                else if (pattern[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                // If pattern and string characters do not match, then
                // update the current cell with 0.
                else
                    dp[i][j] = 0;
            }
        }

        // Returning the value in the bottom-right cell of the DP matrix.
        return dp[str.length()][trueVal];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends