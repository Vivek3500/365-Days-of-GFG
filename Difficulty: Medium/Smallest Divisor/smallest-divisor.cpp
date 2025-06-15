class Solution {
  public:
    int solve(vector<int>&v, int k){
        int maxi = *max_element(v.begin(),v.end());
        int s = 1, e = maxi;
        int ans = -1;
        while(s <= e){
            int mid = (s+e)/2;
            int sum = 0;
            for(auto it:v){
                float d = float(it)/float(mid);
                sum += ceil(d);
            }
            if(sum <= k){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        return solve(arr,k);
    }
};
