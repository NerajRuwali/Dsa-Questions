class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // pointer for child
        int j = 0; // pointer for cookie

        while(i < g.size() && j< s.size()){
         if (s[j] >= g[i]){
            i++;
         }
         j++;
        }
        return i;


        
    }
};