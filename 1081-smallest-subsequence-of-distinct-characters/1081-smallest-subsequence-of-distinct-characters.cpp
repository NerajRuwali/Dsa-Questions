class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(256, -1);

        // Store last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }

        stack<char> st;
        vector<bool> vis(256, false);

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Skip if already present
            if (vis[ch])
                continue;

            // Remove larger characters if they appear later
            while (!st.empty() &&
                   ch < st.top() &&
                   last[st.top()] > i) {
                vis[st.top()] = false;
                st.pop();
            }

            st.push(ch);
            vis[ch] = true;
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

        
