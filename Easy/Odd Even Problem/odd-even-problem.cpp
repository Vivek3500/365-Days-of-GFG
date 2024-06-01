//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        map<char, int>mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }
        int x = 0;
        int y = 0;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            char z = it->first;
            int count = it->second;
            if((z-96)%2==1){
                //odd alphabet
                if(count%2==1) y++;
            }
            else{
                //even alphabet
                if(count%2==0) x++;
            }
        }
        int sum = x+y;
        if(sum%2==0) return "EVEN";
        else return "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends