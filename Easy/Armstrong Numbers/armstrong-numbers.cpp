//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    //Function to Calculate Cube
    int cube(int n){
        return n*n*n;
    }
    //Function to Check Armstrong Number
    string armstrongNumber(int n){
        //Check if n is a 3-digit number
        if(n/1000) return "No";
        //Extract Digits
        int a = n%10, b = (n/10)%10, c = (n/100)%10;
        //Check Armstrong Condition
        if(cube(a)+cube(b)+cube(c) == n) return "Yes";
        else return "No";
        
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends