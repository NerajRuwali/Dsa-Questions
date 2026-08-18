class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
      for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;
      for (int j = i; j < i + k; j++) {
                if (seen.find(nums[j]) == seen.end()) {
                    freq[nums[j]]++;
                    seen.insert(nums[j]);
                }
            }
        }

        int ans = -1;

        for (auto it : freq) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};