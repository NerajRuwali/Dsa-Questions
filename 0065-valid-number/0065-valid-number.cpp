class Solution {
public:
    bool isNumber(string s) {

        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;
        bool digitAfterExponent = true;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;

                if (seenExponent)
                    digitAfterExponent = true;
            }

            else if (c == '+' || c == '-') {
                // sign is only valid at the beginning or after the e/E

                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            else if (c == '.') {
                // Dot cannot appear after exponent or more than once

                if (seenDot || seenExponent)
                    return false;

                seenDot = true;
            }

            else if (c == 'e' || c == 'E') {
                // exponent cannot repeat and must follow a digit

                if (seenExponent || !seenDigit)
                    return false;

                seenExponent = true;
                digitAfterExponent = false;
            }

            else {
                return false;
            }
        }

        return seenDigit && digitAfterExponent;
    }
};