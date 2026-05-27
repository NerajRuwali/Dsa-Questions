class Solution {
public:
    int numberOfSpecialChars(string word) {

        int small[26];
        int capital[26];
        for(int i = 0; i < 26; i++) {
            small[i] = -1;
            capital[i] = -1;
        }
        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];
            if(ch >= 'a' && ch <= 'z') {
                small[ch - 'a'] = i;
            }
            else {

                int idx = ch - 'A';
                if(capital[idx] == -1) {
                    capital[idx] = i;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) {

            if(small[i] != -1 && capital[i] != -1) {

                if(small[i] < capital[i]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};