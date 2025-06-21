class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0)) {
            sign = false;
        }

        unsigned int a = abs((long long)dividend);
        unsigned int b = abs((long long)divisor);
        unsigned int ans = 0;

        while (a >= b) {
            short cnt = 0;
            while (a > (b << (cnt + 1))) {
                cnt++;
            }
            ans += (1 << cnt);
            a -= (b << cnt);
        }

        if (ans == (1 << 31)) {
            return sign ? INT_MAX : INT_MIN;
        }

        return sign ? ans : -ans;
    }
};
