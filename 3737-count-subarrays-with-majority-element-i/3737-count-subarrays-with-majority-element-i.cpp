class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        int ans = 0;

        for (int left = 0; left < n; left++) {

            int targetCount = 0;

            for (int right = left; right < n; right++) {

                if (nums[right] == target)
                    targetCount++;

                int length = right - left + 1;

                if (targetCount > length / 2)
                    ans++;
            }
        }

        return ans;
    }
};