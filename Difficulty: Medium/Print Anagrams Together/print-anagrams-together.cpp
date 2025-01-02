//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        
        for(auto str : arr)  
        {
            
            string key="";
            int freq[26]={0};
            
            for(auto c : str)   
            {
               freq[c-'a']++;    
            }
            
            // generate the key
            
            for(char c='a';c<='z';c++){ 
                key+=freq[c-'a'];
            }
            
            mp[key].push_back(str);
        }
        
        for(auto vec : mp)
        {   
            res.push_back(vec.second);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends