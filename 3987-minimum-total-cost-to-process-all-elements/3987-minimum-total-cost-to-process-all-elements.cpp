class Solution {
public:
    const long long MOD = 1e9 + 7;

    int minimumCost(vector<int>& nums, int k) {
        long long resources = k;
        long long nextCost = 1;
        long long ans = 0;

        for (int num : nums) {
            if (resources < num) {
                long long ops = (num - resources + k - 1) / k;

                long long first = ops;
                long long second = 2 * nextCost + ops - 1;

                if (first % 2 == 0)
                    first /= 2;
                else
                    second /= 2;

                long long add = ((first % MOD) * (second % MOD)) % MOD;

                ans = (ans + add) % MOD;

                resources += ops * 1LL * k;
                nextCost += ops;
            }

            resources -= num;
        }

        return ans;
    }
};