class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> candies(n,1);
         // is hum left and right dono se check krenge 
        for(int i=1;i<n;i++){ // left se check
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        for(int i=n-2;i>=0;i--){  // right se check
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        int sum = 0;
        for(int c : candies){
            sum += c;
        }

        return sum;
    }
};