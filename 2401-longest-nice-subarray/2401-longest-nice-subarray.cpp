class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int bitMask = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); right++) {

            while ((bitMask & nums[right]) != 0) {
                bitMask ^= nums[left];
                left++;
            }

            bitMask |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};