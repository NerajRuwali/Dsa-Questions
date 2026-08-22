class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int number = n;

        while (number > 0) {
            int digit = number % 10;

            digitSum += digit;
            digitProduct *= digit;

            number /= 10;
        }

        int divisor = digitSum + digitProduct;

        return n % divisor == 0;
    }
};