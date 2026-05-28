class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int sum = 0;
        int mini = 0;

        for(int num: nums){
            sum+= num;
            mini = min(mini , sum);
        }
        return 1-mini;

        
    }
};