class Solution {
public:
    int maxProduct(int n) {
        int largestDigit = 0;
        int secondLargestDigit = 0;

        while(n > 0){
            int currentDigit = n % 10;
            n /= 10;

            if(currentDigit >= largestDigit){
                secondLargestDigit = largestDigit;
                largestDigit = currentDigit;
            }
            else if( currentDigit> secondLargestDigit){
                secondLargestDigit = currentDigit;
            }
        }
        return largestDigit * secondLargestDigit;
        
    }
};