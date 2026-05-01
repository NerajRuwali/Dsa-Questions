class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        long F = 0;
        for(int a = 0; a < n; a++) {
            sum += nums[a];
            F += a * nums[a];
        }
        
        long ans = F;
        for(int k = 1; k < n; k++) {
            F = F + sum - (long)n * nums[n - k];
            ans = max(ans, F);
        }
        
        return ans;
    }
};