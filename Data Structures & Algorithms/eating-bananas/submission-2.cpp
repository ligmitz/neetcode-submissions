class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int answer = high;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            int total_time = 0;
            for (int pile:piles) {
                total_time += ceil((double)pile / mid);
            }

            if (total_time <= h) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};
