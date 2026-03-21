class Solution {
public:

    int daysNeeded(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > cap) {
                days++;
                load = w;
            } else {
                load += w;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int requiredDays = daysNeeded(weights, mid);

            if (requiredDays <= days) {
                ans = mid;
                right = mid - 1; // try smaller capacity
            } else {
                left = mid + 1;  // need bigger capacity
            }
        }

        return ans;
    }
};