class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int one_skip = arr[0];
        int no_skip = arr[0];
        int overall_best = arr[0];

        for(int i = 1 ; i< arr.size(); i++){

            one_skip = max(one_skip+ arr[i] , no_skip );
            no_skip = max(no_skip + arr[i], arr[i]);

            overall_best = max({overall_best , no_skip , one_skip});
        }
        return overall_best;
        
    }
};