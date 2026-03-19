class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();

        // Traverse from last digit
        for(int i = n - 1; i >= 0; i--) {
            
            if(digits[i] < 9) {
                digits[i]++;    //simply add 1
                return digits;
            }

            // if digit is 9 make it 0 and continue
            digits[i] = 0;
        }

        
        digits.insert(digits.begin(), 1);

        return digits;
    }
};