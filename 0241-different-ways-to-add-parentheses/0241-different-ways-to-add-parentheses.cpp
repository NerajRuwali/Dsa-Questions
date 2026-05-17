class Solution {
public:

    vector<int> solve(string expression) {

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {

            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                vector<int> left = solve(expression.substr(0, i));
                vector<int> right = solve(expression.substr(i + 1));

                for (int a : left) {
                    for (int b : right) {

                        if (ch == '+') {
                            ans.push_back(a + b);
                        }
                        else if (ch == '-') {
                            ans.push_back(a - b);
                        }
                        else {
                            ans.push_back(a * b);
                        }
                    }
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {

        return solve(expression);
    }
};