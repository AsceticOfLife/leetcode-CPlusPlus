#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            long long s = (long long)(mid) * mid;
            if (s > num) right = mid - 1;
            else if (s < num) left = mid + 1;
            else return true;
        }

        return false;
    }
};



int main() {
    Solution s;
    cout << s.isPerfectSquare(2147395600);
    
    return 0;
}