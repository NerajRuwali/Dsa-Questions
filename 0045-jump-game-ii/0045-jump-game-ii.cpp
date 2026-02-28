class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for(int i = 0; i < n - 1; i++) {
            
            // Update farthest reachable index
            farthest = max(farthest, i + nums[i]);

            // If we reach end of current range
            if(i == currentEnd) {
                jumps++;                 // Make a jump
                currentEnd = farthest;   // Update new range
            }
        }

        return jumps;
    }
};