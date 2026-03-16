class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans(n);

        int positive = 0;
        int negative = 1;

        for(int i = 0; i < n; i++){

            if(nums[i] > 0){
                ans[positive] = nums[i];
                positive += 2;
            }
            else{
                ans[negative] = nums[i];
                negative += 2;
            }
        }

        return ans;
    }
};