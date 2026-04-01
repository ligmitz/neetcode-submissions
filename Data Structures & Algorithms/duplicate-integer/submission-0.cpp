class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> count;
        for (auto num: nums) {
            if (count.find(num) == count.end()) {
                count[num] = 1;
            } else {count[num]++;}
            if (count[num] > 1) return true;
        }
        return false;
    }
};