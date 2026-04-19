class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;

     int totalSum = 0;
        for(int x : cardPoints) totalSum += x;

        if(windowSize == 0) return totalSum;

      int currSum = 0;
        for(int i = 0; i < windowSize; i++)
            currSum += cardPoints[i];

        int minSum = currSum;

        for(int i = windowSize; i < n; i++) {
          currSum += cardPoints[i];
            currSum -= cardPoints[i - windowSize];
            minSum = min(minSum, currSum);
        }

        return totalSum - minSum;
    }
};