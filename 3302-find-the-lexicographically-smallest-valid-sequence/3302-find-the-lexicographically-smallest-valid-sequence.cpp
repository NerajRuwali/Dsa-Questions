class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<int> suf(n + 1, 0);
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                suf[i] = suf[i + 1] + 1;
                j--;
            } else {
                suf[i] = suf[i + 1];
            }
        }
        
        vector<int> ans;
        int j = 0;
        bool changed = false;
        
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } 
            else if (!changed && suf[i + 1] >= m - j - 1) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }
        
        if (ans.size() == m)
            return ans;
        
        return {};
    }
};