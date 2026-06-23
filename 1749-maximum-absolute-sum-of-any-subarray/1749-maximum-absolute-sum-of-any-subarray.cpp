class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int currMax = 0, maxSum = 0;
        int currMin = 0, minSum = 0;

        for (int num : nums) {

            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }

        return max(maxSum, -minSum);
    }
};