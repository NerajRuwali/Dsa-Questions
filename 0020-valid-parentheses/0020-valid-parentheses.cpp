class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {

            // If opening bracket push in the stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // If stack empty then it is invalid
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching pair
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack empty it is valid
        return st.empty();
    }
};