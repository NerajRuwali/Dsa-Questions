class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, vector<int>> group;
        unordered_map<int, int> groupId;
        unordered_map<int, int> pos;

        int id = 1;

        // Build groups
        group[id].push_back(sorted[0]);

        for(int i = 1; i < n; i++){
            if(sorted[i] - sorted[i - 1] > limit){
                id++;
            }

            group[id].push_back(sorted[i]);
        }

        // Store group id of every value
        id = 1;

        for(int i = 0; i < n; i++){
            if(i > 0 && sorted[i] - sorted[i - 1] > limit){
                id++;
            }

            groupId[sorted[i]] = id;
        }

        // Position pointer for each group
        for(int i = 1; i <= id; i++){
            pos[i] = 0;
        }

        // Rebuild nums using the smallest
        // available value from its group
        for(int i = 0; i < n; i++){
            int grp = groupId[nums[i]];

            nums[i] = group[grp][pos[grp]];
            pos[grp]++;
        }

        return nums;
    }
};