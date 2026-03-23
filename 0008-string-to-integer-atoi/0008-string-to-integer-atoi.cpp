class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // whitespace skip
        while (i < n && s[i] == ' ') i++;
        
        // its check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        // digit me convert karne ke lie
        long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // handle ko overflow karna
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return sign * result;
    }
};