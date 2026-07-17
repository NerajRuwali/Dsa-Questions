class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // if k left
        while (k > 0) {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (i < res.size() && res[i] == '0') i++;

        res = res.substr(i);

        return res == "" ? "0" : res;
    }
};