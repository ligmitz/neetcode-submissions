class Solution {
public:
    int squares(int n, unordered_map<int, int>& summations) {
        int summ = 0;
        while (n / 10) {
            summ += pow(n % 10, 2);
            n /= 10;
        }
        summ += pow(n, 2);
        summations[n] = summ;
        return summ;
    }

    bool isHappy(int n) {
        unordered_map<int, int> summations;
        while(true) {
            if (summations.find(n) != summations.end()) {
                return false;
            }
            n = squares(n, summations);
            if (n == 1) return true;
        }
        return true;
    }
};
