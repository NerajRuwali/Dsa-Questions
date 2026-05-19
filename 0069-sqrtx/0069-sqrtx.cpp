class Solution {
public:
    int mySqrt(int x) {

        long long left = 0;
        long long right = x;

        int ans = 0;

        while( left <=right ){

            long long mid = left + ( right - left)/2;

            long long square = mid * mid;

            if(square == x){
                return mid;
            }
             else if(square <x){
                ans = mid;
                left = mid +1;
             }
             else {
                right = mid -1;
             }
        }
        return ans;


    }
};