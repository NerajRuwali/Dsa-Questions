class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> mp;

        while(n > 0) {
            string state;

            for(int x : cells)
                state += char(x + '0');

            if(mp.find(state) != mp.end()) {
                int cycle = mp[state] - n;
                n %= cycle;
            } else {
                mp[state] = n;
            }

            if(n == 0)
                break;

            n--;

            vector<int> next(8, 0);

            for(int i = 1; i < 7; i++) {
                if(cells[i-1] == cells[i+1])
                    next[i] = 1;
            }

            cells = next;
        }

        return cells;
    }
};