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

        // agar k abhi bhi bacha hai
        while (k > 0) {
            st.pop();
            k--;
        }

        // build result
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        // remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;

        res = res.substr(i);

        return res == "" ? "0" : res;
    }
};