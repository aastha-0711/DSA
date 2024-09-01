class Solution {
public:
    int reverse(int x) {
    int reversed = 0;
    int digit;

    while (x != 0) {
        digit = x % 10;
        // Check for overflow before adding the digit
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return 0; // Overflow occurred
        }

        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < INT_MIN % 10)) {
            return 0; // Underflow occurred
        }

        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return reversed;
}};