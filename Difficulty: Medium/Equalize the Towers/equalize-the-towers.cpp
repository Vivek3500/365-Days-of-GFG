class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int, int>> towers(n);
        for (int i = 0; i < n; i++) {
            towers[i] = {heights[i], cost[i]};
        }
        sort(towers.begin(), towers.end());
        long long totalWeight = 0;
        for (auto& it : towers) {
            totalWeight += it.second;
        }
        long long currWeight = 0;
        int medianHeight = 0;
        for (auto& it : towers) {
            currWeight += it.second;
            if (currWeight >= (totalWeight + 1) / 2) {
                medianHeight = it.first;
                break;
            }
        }
        long long totalCost = 0;
        for (auto& it : towers) {
            totalCost += 1LL * abs(it.first - medianHeight) * it.second;
        }

        return totalCost;
    }
};