class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int i = 0;
        while(colors[i] == colors[n-1]) i++;

        int j = n - 1;
        while(colors[j] == colors[0]) j--;

        return max(n - 1 - i, j);
    }
};