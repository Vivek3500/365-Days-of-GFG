//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        // Code here.
        int n = arr.size();
        int s = 0,e = n-1;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            int num = arr[mid];
            
            if((mid > 0 && arr[mid] > arr[mid-1]) && (mid<n-1 && arr[mid] > arr[mid+1])) return arr[mid];
            else if(mid < n-1 && arr[mid] > arr[mid+1]){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        
        if(arr[n-1] > arr[n-2] && arr[n-1] > arr[0]) return arr[n-1];
        return arr[0];
        
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends