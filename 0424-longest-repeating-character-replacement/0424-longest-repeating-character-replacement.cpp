class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        unordered_set<char>st(s.begin(), s.end());
        for(char ch : st){
            int count = 0;
            int left = 0;
            for(int right = 0 ; right < s.size(); right++){
                if(s[right]== ch){
                    count++;
                }
                while((right-left+1) - count>k){
                    if(s[left]==ch){
                        count--;
                    }
                    left++;
                }
                ans = max(ans , right - left +1 );
            }
        }
        return ans;
    }
};



        