class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop(); // stack asteroid destroyed
                }
                else if (abs(st.top()) == abs(a)) {
                    st.pop(); // both destroyed
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true; // current destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};