class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = -1;

        int i = 0;
        while(i < n-1) {
            if(nums[i+1] - nums[i] != 1){
                i++;
                continue;
            }
            int j = i+1;
            int expectedDifference = -1;

            while( j < n-1 && nums[j+1] - nums[j] == expectedDifference) {
                expectedDifference *= -1;
                j++;
            }
            maxLength = max(maxLength , j-i+1);
            i = j;
        }
        return maxLength;
        
    }
};