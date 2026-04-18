class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // shrink krdo window ko agar k se jyada replacemnet krne ki jrurat pd rhi ha toh
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};