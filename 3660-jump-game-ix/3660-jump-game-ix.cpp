class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        int maxi = nums[0];

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            ans[i] = maxi;
        }
        int mini = INT_MAX;
       for(int i = n - 1; i >= 0; i--) {
       if(ans[i] > mini) {
                if(i + 1 < n) {
                    ans[i] = ans[i + 1];
                }
            }
          mini = min(mini, nums[i]);
        }

        return ans;
    }
};