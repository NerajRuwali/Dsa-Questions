class Solution {
public:
    int countAsterisks(string s) {

        bool insidePipe = false;
        int count = 0;

        for (char ch : s) {

            if (ch == '|') {
                insidePipe = !insidePipe;
            }
            else if (ch == '*' && !insidePipe) {
                count++;
            }
        }

        return count;
    }
};