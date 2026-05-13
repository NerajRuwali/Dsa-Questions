class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int ans = 0;
        int mask = 0;

        for(int bit = 31; bit >= 0; bit--) {

            mask |= (1 << bit);

            unordered_set<int> st;

            for(int x : nums) {
                st.insert(x & mask);
            }

            int candidate = ans | (1 << bit);

            for(int prefix : st) {

                if(st.count(prefix ^ candidate)) {
                    ans = candidate;
                    break;
                }
            }
        }

        return ans;
    }
};