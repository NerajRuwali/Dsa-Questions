class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int >mp;
         mp[0] = 1;
         int prefixSum = 0;
         int count = 0;

         for(int num:nums){
            prefixSum += num;

            int rem = prefixSum%k;

            if(rem<0){
                rem += k;
            }
            count += mp[rem];
            mp[rem]++;
         }
         return count;
        
    }
};