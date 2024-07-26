//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool kPangram(string str, int k) {
        // Removing spaces from the string
        for (int i = 0; i < str.length(); i++)
            if (str[i] == ' ')
                str.erase(str.begin() + i);

        // If the length of the string is less than 26, it can't be a pangram
        if (str.length() < 26)
            return false;

        // If k is greater than 25, it will always be a pangram
        if (k > 25)
            return true;
        else {
            // Creating a map to store occurrence of each character in the string
            int map[26] = {0};

            // Updating the map with occurrence of each character
            for (int i = 0; i < str.length(); i++)
                map[str[i] - 'a'] = 1;

            // Counting the number of distinct characters in the string
            int count = 0;
            for (int i = 0; i < 26; i++) {
                if (map[i] == 1)
                    count++;
            }

            // Checking if the number of distinct characters plus k is at least 26
            if (count + k >= 26)
                return true;
            else
                return false;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends