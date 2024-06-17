class Solution {
public:
    bool checkifPerfectSquare(int n) {
        if (n <= 1) {
            return true;
        }

        long long left = 1, right = n;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == n) {
                return true;
            } else if (square < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
    
    bool judgeSquareSum(int c) {
        for (int b = 0; b <= sqrt(c); b++) {
            int val = c - (b * b);
            if (checkifPerfectSquare(val)) {
                return true;
            }
        }
        return false;
    }
};
