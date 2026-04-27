class Solution {
    public:
    int rob(vector <int> & nums) {
        int loot = 0;
        int skip = 0;

        for(int money: nums) {
            int newLoot = skip + money;
            int newSkip = max(loot , skip);

            loot = newLoot;
            skip = newSkip;
        }
        return max(loot,skip);
    }
};
