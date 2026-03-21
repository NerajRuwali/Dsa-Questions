class Solution {
public:

    int computeSum(vector<int>& nums, int d) {
        int sum = 0;
        for (int x : nums) {
            sum += (x + d - 1) / d;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int sum = computeSum(nums, mid);

            if (sum <= threshold) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }

        return ans;
    }
};