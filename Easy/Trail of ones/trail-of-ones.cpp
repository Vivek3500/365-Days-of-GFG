//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        int ans=0;
        int a=0;
        int b=1;
        for(int i=2;i<=n;i++){
            ans=((ans*2)%1000000007+b)%1000000007;
            int temp=b;
            b=(a+b)%1000000007;
            a=temp;
        }
        return ans%1000000007;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends