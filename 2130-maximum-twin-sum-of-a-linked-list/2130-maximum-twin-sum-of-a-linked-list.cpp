
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int result = 0;
        int n = nums.size();
        for(int i = 0 ; i< n/2; i++){
            result = max(result , nums[i] + nums[n-1-i]);
        }
        return result;
    }
};