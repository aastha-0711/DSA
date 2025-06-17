class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n; // Safely promote to avoid overflow
        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }

        if (nn == 0) return 1;
        if (nn % 2 == 0) {
            return myPow(x * x, nn / 2);
        } else {
            return x * myPow(x, nn - 1);
        }
    }
};
