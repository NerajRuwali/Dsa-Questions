class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> uglyNumbers(n);

        uglyNumbers[0] = 1;

        int pointerTwo = 0;
        int pointerThree = 0;
        int pointerFive = 0;
         for(int index = 1 ; index < n; index++){
            int nextMultipleOfTwo = uglyNumbers[pointerTwo] * 2;
            int nextMultipleOfThree = uglyNumbers[pointerThree] * 3;
            int nextMultipleOfFive = uglyNumbers[pointerFive] * 5;

            int nextUglyNumber = min(nextMultipleOfTwo , min(nextMultipleOfThree , nextMultipleOfFive));

            uglyNumbers[index] = nextUglyNumber;

            if(nextUglyNumber == nextMultipleOfTwo){
                pointerTwo++;
            }
            if(nextUglyNumber == nextMultipleOfThree){
                pointerThree++;
            }
            if(nextUglyNumber == nextMultipleOfFive){
                pointerFive++;
            }
         }
         return uglyNumbers[n-1];
        
    }
};