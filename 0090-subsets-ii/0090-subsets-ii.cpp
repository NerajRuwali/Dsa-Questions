class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(0, nums, temp, ans);
        return ans;
    }

    void backtrack(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            backtrack(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }
};