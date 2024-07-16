//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string printString(string &str, char ch, int count) {
        int occ = 0, i;

        // Start traversing the string
        for (i = 0; i < str.size(); i++) {

            // Increment occ if current char is equal
            // to given character
            if (str[i] == ch)
                occ++;

            // Break the loop if given character has
            // been occurred given no. of times
            if (occ == count)
                break;
        }

        // Print the string after the occurrence
        // of given character given no. of times
        if (i < str.length() - 1)
            return str.substr(i + 1, str.length() - (i + 1));

        // Otherwise string is empty
        else
            return "";
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends