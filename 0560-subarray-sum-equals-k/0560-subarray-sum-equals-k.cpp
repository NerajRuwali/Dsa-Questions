class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1; // basically hands case like {3,2} and target i.e k is 5

        int sum =0, count = 0;

        for(int num: nums){
            sum+= num;

            if(mp.find(sum-k)!= mp.end()){
                count+= mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
        
    }
};