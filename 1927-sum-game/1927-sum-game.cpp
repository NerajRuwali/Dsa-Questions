class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;

        int leftQuestion = 0;
        int rightQuestion = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                leftQuestion++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        // Second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                rightQuestion++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice wins
        if ((leftQuestion + rightQuestion) % 2 == 1) {
            return true;
        }

        int sumDifference = leftSum - rightSum;

        // IMPORTANT: right - left
        int questionDifference = rightQuestion - leftQuestion;

        // Bob wins if the difference can be exactly balanced
        if (2 * sumDifference == 9 * questionDifference) {
            return false;
        }

        // Otherwise Alice wins
        return true;
    }
};