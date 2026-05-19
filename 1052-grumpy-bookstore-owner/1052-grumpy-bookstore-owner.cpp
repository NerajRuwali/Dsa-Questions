class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();

        int satisfied = 0;

        // already satisfied customers
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        int extra = 0;

        // first window
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
        }

        int maxExtra = extra;

        // sliding window
        for (int i = minutes; i < n; i++) {

            // add new element
            if (grumpy[i] == 1) {
                extra += customers[i];
            }

            // remove old element
            if (grumpy[i - minutes] == 1) {
                extra -= customers[i - minutes];
            }

            maxExtra = max(maxExtra, extra);
        }

        return satisfied + maxExtra;
    }
};