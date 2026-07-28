class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> frequency(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        string firstHalf = "";
        char middleCharacter = '\0';

        // Build first half
        for (int i = 0; i < 26; i++) {

            int repeat = frequency[i] / 2;

            while (repeat--) {
                firstHalf += char(i + 'a');
            }

            if (frequency[i] % 2 == 1) {
                middleCharacter = char(i + 'a');
            }
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (middleCharacter != '\0') {
            return firstHalf + middleCharacter + secondHalf;
        }

        return firstHalf + secondHalf;
    }
};