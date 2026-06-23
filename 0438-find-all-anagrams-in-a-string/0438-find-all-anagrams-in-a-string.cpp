class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;

        vector<int>pCount(26,0);
        vector<int>sCount(26,0);

        for(char ch:p){
            pCount[ch - 'a']++;
        }
        int k = p.size();
        for(int i  = 0 ;i< s.size(); i++){

            sCount[s[i]-'a']++;

            if(i>=k){
                sCount[s[i-k]-'a']--;
            }
            if(sCount==pCount){
                ans.push_back(i-k+1);
            }
        }
        return ans;
        
    }
};