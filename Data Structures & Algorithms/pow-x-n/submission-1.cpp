class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1;

        if (n > 0) {
            while (n--) {
                answer *= x;
            }
        } else if (n < 0) {
            while (n++) {
                answer /= x;
            }
        }
        return answer;
    }
};
