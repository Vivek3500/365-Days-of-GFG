//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findClosest(int n, int k, int arr[]) {
        // Perform binary search to find the insertion point for 'k'
        int ind = std::lower_bound(arr, arr + n, k) - arr;

        // If 'k' is less than or equal to the first element, return the first element
        if (ind == 0) {
            return arr[0];
        }

        // If 'k' is greater than the last element, return the last element
        if (ind == n) {
            return arr[n - 1];
        }

        // Retrieve the closest elements around the found index
        int leftElement = arr[ind - 1];
        int rightElement = arr[ind];

        // Compute the absolute differences to find the closest value
        int leftDiff = std::abs(leftElement - k);
        int rightDiff = std::abs(rightElement - k);

        // If the differences are equal, return the greater value
        if (leftDiff == rightDiff) {
            return rightElement;
        }

        // Otherwise, return the element with the smaller difference
        return (leftDiff < rightDiff) ? leftElement : rightElement;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends