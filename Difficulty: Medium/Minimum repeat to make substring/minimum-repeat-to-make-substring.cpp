//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        int ans = 1 , n1 = s1.size() ;string s = s1;
        while(n1<s2.size()){
            ans++;
            n1+=s1.size();
            s+=s1;
        }
        if(s.find(s2)!=string::npos)return ans;
        ans++;
        s+=s1;
        if(s.find(s2)!=string::npos)return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends