class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int start = 0;
        int end = 0;
        int sum = 0;
        int total = INT_MAX; 
        
        while(end < n) {
            
            sum += nums[end];  // add number to the sum
            
            // window ki length ko decrease krna ha 
            while(sum >= target) {
                total = min(total, end - start + 1);
                sum -= nums[start];   
                start++;
            }
            
            end++;
        }

        return (total == INT_MAX) ? 0 : total;
    }
};