//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> right(n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty()>0 && st.top()>=arr[i]){
                st.pop();
            }
            
            right[i] = st.empty() ? 0 : st.top();
            st.push(arr[i]);
        }
        
        st = stack<int>();
        
        int ans=0;
        for(int i=0;i<n;i++){
            int rs = right[i];
            
            while(!st.empty()>0 && st.top()>=arr[i]){
                st.pop();
            }
            
            int ls = st.empty() ? 0 : st.top();
            st.push(arr[i]);
            
            ans = max(ans, abs(ls-rs) );
            
            // cout<<ls<<" "<<rs<<endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends