//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
void rearrange(vector<int> &arr) {
        vector<int> p , n;
        for(auto it : arr){
            if(it >= 0) p.push_back(it);
            else n.push_back(it);
        }
        
        int i = 0 , j = 0;
        vector<int> ans;
       while (i < p.size() && j < n.size()) {
        ans.push_back(p[i++]);  
        ans.push_back(n[j++]);  
    }

    while (i < p.size()) {
        ans.push_back(p[i++]);
    }

    while (j < n.size()) {
        ans.push_back(n[j++]);
    }

    arr = ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends