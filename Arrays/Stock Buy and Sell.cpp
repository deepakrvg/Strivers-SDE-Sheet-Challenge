class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int mn = 10004;
        for (int i = 0; i < n; i++) {
            if (mn > prices[i]) {
                mn = prices[i];
            }
            ans = max(ans, prices[i] - mn);
        }
        return ans;
    }
};
