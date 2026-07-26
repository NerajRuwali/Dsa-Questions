class Solution {
public:
    int countBinarySubstrings(string s) {

        int previousGroup = 0;
        int currentGroup = 1;
        int answer = 0;

        for (int i = 1; i < s.size(); i++) {

            if (s[i] == s[i - 1]) {
                currentGroup++;
            }
            else {
                answer += min(previousGroup, currentGroup);

                previousGroup = currentGroup;
                currentGroup = 1;
            }
        }

        answer += min(previousGroup, currentGroup);

        return answer;
    }
};