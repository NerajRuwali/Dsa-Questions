class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        // MIN contribution
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                res -= (long long)nums[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // MAX contribution
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                res += (long long)nums[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        return res;
    }
};