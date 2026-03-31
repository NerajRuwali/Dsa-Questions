class Solution {
public:
    void solve(int open, int close, string s, vector<string>& ans, int n) {
        if(s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if(open < n)
            solve(open + 1, close, s + '(', ans, n);

        if(close < open)
            solve(open, close + 1, s + ')', ans, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, "", ans, n);
        return ans;
    }
};