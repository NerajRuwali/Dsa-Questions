class Solution {
public:
    int subtractProductAndSum(int n) {

        long long mul = 1;
        int sum = 0;

        while(n!=0){

            int digit = n%10;
            n = n/10;

            mul = mul * digit ;
            sum = sum + digit;
        }
        int answer = mul - sum;
        return answer;
    }
};

        