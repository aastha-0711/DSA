class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        
        // Handle negative exponent
        if (nn < 0) {
            x = 1.0 / x;
            nn = -nn;
        }
        
        while (nn > 0) {
            if (nn % 2 == 1) {  // If nn is odd
                ans *= x;
            }
            x *= x;
            nn /= 2;
        }
        
        return ans;
    }
};
