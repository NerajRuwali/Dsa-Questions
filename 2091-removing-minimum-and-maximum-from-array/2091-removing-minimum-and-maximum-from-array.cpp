class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // 1. Both removed from left
        int removeLeft = right + 1;

        // 2. Both removed from right
        int removeRight = n - left;

        // 3. One from left, one from right
        int removeBoth = (left + 1) + (n - right);

        return min({removeLeft, removeRight, removeBoth});
    }
};