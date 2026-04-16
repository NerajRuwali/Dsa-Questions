class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge; // next greater map
        stack<int> st;

      
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        
        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }

        
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nge[num]);
        }

        return ans;
    }
};