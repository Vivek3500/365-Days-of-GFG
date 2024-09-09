//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n =arr.size();
        int i =0;
        int j =n-1;
        while(j > i){
            if(arr[i] == 2){
                while(arr[j] != 0 && j > i){
                    j--;
                }
                swap(arr[i],arr[j]);
            }if(arr[i] == 1){
                while(arr[j] != 0 && j > i){
                    j--;
                }
                swap(arr[i],arr[j]);
            }
            i++;
        }
        i =0;
        while(i < n && arr[i] != 2){
            i++;
        }
        j =n-1;
        while(j> i){
            if(arr[i] == 2){
                while(arr[j] != 1 && j > i){
                    j--;
                }
                swap(arr[i],arr[j]);
            }
            i++;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends