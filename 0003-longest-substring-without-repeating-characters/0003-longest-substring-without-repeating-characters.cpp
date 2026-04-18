class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> longest(256, -1);
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            if (longest[s[right]] != -1) {
                left = max(left, longest[s[right]] + 1);
            }

            longest[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};