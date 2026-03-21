class Solution {
public:

    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, bouquets = 0;

        for (int d : bloomDay) {
            if (d <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m * k;

        if (total > bloomDay.size()) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;  
            }
        }

        return ans;
    }
};