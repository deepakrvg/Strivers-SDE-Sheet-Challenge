class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
            // cout << nums[i] << " ";
        }
        int i = 0;
        for (i = 0; i < n; i++) {
            if (nums[i] / n > 1) {
                break;
            }
        }
        return i + 1;
    }
};
