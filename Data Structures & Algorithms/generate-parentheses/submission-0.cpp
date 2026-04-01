class Solution {
public:
    void recursive_generation(string par, int left, int right, int n, vector<string>& result) {
        if (right == 0) {
            result.push_back(par);
            return;
        }
        if (left == 0) {
            recursive_generation(par + ")", left, right - 1, n, result);
        } else {
            recursive_generation(par + "(", left - 1, right, n, result);
            if (left < right) recursive_generation(par + ")", left, right - 1, n, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        int left = n, right = n;
        vector<string> result;
        recursive_generation("", left, right, n, result);
        return result;
    }
};
