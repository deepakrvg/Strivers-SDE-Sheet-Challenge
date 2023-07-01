class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        bool flag = 0;
        while (i > 0) {
            if (nums[i] > nums[i - 1]) {
                i--;
                flag = 1;
                break;
            }
            i--;
        }

        if (!flag) {
            int l = 0, r = n - 1;
            while (l <= r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            return;
        }

        int j = i + 1;
        // int num = nums[i];
        int just_bigger_index = i + 1;
        while (j < n && nums[i] < nums[j]) {
            just_bigger_index = j;
            j++;
        }
        swap(nums[i], nums[just_bigger_index]);
        cout << "i = " << i << "\tindex = " << just_bigger_index << "\n";
        sort(nums.begin() + i + 1, nums.end());
    }
};
