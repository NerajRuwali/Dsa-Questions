class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        vector<long long>ans(n);
        //sari index store karunga with same value
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        //ik ik karke iterate 
        for(auto &it:mpp){
            vector<int>&pos=it.second;
            int m=pos.size();
            long long sum=0;
            for(auto it:pos){
                sum+=it;
            }
            long long l_sum=0;
            
             for(int i=0;i<m;i++){
               long long  r_sum=sum-l_sum-pos[i];
                long long left=1LL*pos[i]*i-l_sum;
                long long right=r_sum-1LL*pos[i]*(m-i-1);
                 ans[pos[i]]=left+right;
                 l_sum+=pos[i];
             }
        }
        return ans;
    }
};