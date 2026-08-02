class Solution {
public:
    int minimumCost(int index, vector<int>& days, vector<int>& costs,
                    vector<int>& dp) {

        if (index >= days.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // Buy 1-day pass
        int oneDayCost =
            costs[0] + minimumCost(index + 1, days, costs, dp);

        // Buy 7-day pass
        int nextIndex = index;
        while (nextIndex < days.size() &&
               days[nextIndex] < days[index] + 7) {
            nextIndex++;
        }

        int sevenDayCost =
            costs[1] + minimumCost(nextIndex, days, costs, dp);

        // Buy 30-day pass
        nextIndex = index;
        while (nextIndex < days.size() &&
               days[nextIndex] < days[index] + 30) {
            nextIndex++;
        }

        int thirtyDayCost =
            costs[2] + minimumCost(nextIndex, days, costs, dp);

        return dp[index] =
                   min({oneDayCost, sevenDayCost, thirtyDayCost});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);

        return minimumCost(0, days, costs, dp);
    }
};