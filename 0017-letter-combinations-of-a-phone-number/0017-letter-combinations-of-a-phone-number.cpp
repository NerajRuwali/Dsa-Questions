class Solution {
public:
    void solve(int index, string digits, string temp, vector<string>& ans, vector<string>& map) {
        
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = map[digits[index] - '0'];

        for(char ch : letters) {
            solve(index + 1, digits, temp + ch, ans, map);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans;
        solve(0, digits, "", ans, map);
        return ans;
    }
};