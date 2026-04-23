class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int case1 = robLine(nums, 0, n - 2);
        int case2 = robLine(nums, 1, n - 1);
        return max(case1, case2);
    }
    int robLine(vector<int>& nums, int start, int end) {
        int loot = 0, skip = 0;
    for(int i = start; i <= end; i++) {
            int newLoot = skip + nums[i];
            int newSkip = max(loot, skip);
            loot = newLoot;
            skip = newSkip;
        }
            return max(loot, skip);
    }
};