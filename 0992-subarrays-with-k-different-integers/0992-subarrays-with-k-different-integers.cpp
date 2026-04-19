class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left = 0, ans = 0;

        for(int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            if(mp[nums[right]] == 1) k--; 

            while(k < 0) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) k++; 
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};