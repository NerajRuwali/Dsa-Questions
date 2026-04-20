class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int, int> mp;

        for(int num : hand) {
            mp[num]++;
        }

        while(!mp.empty()) {
            int start = mp.begin()->first;

            
            for(int i = 0; i < groupSize; i++) {
                int curr = start + i;

                if(mp.find(curr) == mp.end()) {
                    return false;
                }

                mp[curr]--;

                if(mp[curr] == 0) {
                    mp.erase(curr);
                }
            }
        }

        return true;
    }
};