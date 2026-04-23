class Solution {
public:
    int rob(vector<int>& nums) {
        int loot = 0; // loot current
        int skip = 0; // skip current

        for(int money : nums) {
            int newLoot = skip + money; // agar loot kiya
            int newSkip = max(loot, skip); // agar skip kiya

            loot = newLoot;
            skip = newSkip;
        }

        return max(loot, skip);
    }
};
