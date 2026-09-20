class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for(int i = 0 ; i< s.length(); i++){
            int reversePos = 'z' - s[i] + 1;

            result += (i+1) * reversePos;
        }
        return result;
        
    }
};