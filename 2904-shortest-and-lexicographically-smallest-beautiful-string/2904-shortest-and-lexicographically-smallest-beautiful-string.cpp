class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        string answer = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1') {
                ones++;
            }

            // If we have more than k ones,
            // move left until we have at most k ones
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Now we have exactly k ones
            if (ones == k) {

                // Remove unnecessary leading zeros
                while (left < right && s[left] == '0') {
                    left++;
                }

                string current = s.substr(left, right - left + 1);

                // Check shortest and lexicographically smallest
                if (answer.empty() ||
                    current.length() < answer.length() ||
                    (current.length() == answer.length() &&
                     current < answer)) {

                    answer = current;
                }
            }
        }

        return answer;
    }
};