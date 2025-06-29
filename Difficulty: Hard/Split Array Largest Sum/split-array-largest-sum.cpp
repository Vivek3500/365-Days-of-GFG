class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        // Helper function to check if we can split array into k parts
        // with each part having sum <= maxSum
        auto canSplit = [&](int maxSum) -> bool {
            int parts = 1;  // Start with 1 part
            int currentSum = 0;
            
            for (int num : arr) {
                // If adding current number exceeds maxSum, start new part
                if (currentSum + num > maxSum) {
                    parts++;
                    currentSum = num;  // Start new part with current number
                    
                    // If we need more than k parts, it's impossible
                    if (parts > k) return false;
                } else {
                    currentSum += num;  // Add to current part
                }
            }
            
            return true;  // Successfully split into <= k parts
        };
        
        // Binary search bounds
        int left = *max_element(arr.begin(), arr.end());  // Minimum possible answer
        int right = accumulate(arr.begin(), arr.end(), 0);  // Maximum possible answer
        
        // Binary search for the minimum possible maximum sum
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If we can split with max sum = mid, try smaller sum
            if (canSplit(mid)) {
                right = mid;
            } else {
                // If we can't split with max sum = mid, need larger sum
                left = mid + 1;
            }
        }
        
        return left;  // left == right at this point
    }
};