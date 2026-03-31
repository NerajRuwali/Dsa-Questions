class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        long long res = 1;
        while(n > 0) {
            if(n % 2 == 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            n /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = (power(5, even) * power(4, odd)) % MOD;
        return ans;
    }
};