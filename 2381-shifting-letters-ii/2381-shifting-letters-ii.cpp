class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       int n = s.size();
       vector<int> diff(n + 1, 0);

        for (auto &q : shifts) {

            int l = q[0];
            int r = q[1];
            int dir = q[2];

            if (dir == 1) {
                diff[l]++;
                diff[r + 1]--;
            } else {
                diff[l]--;
                diff[r + 1]++;
            }
        }

        int cur = 0;

        for (int i = 0; i < n; i++) {

            cur += diff[i];

            int val = (s[i] - 'a' + cur) % 26;

            if (val < 0)
                val += 26;

            s[i] = 'a' + val;
        }

        return s;
    }
};