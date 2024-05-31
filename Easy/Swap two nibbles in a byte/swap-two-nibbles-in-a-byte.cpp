//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        // Convert the decimal number to binary string
        string binaryStr = bitset<8>(n).to_string();

        // Swap the nibbles (first 4 bits with last 4 bits)
        string swappedStr = binaryStr.substr(4) + binaryStr.substr(0, 4);

        // Convert the swapped binary string back to decimal
        int result = stoi(swappedStr, nullptr, 2);
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends