/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = fruits.size();
        // 创建窗口，里面是种类
        unordered_map<int, int> window;
        int max_len = 0;

        int left, right;
        left = right = 0;

        while (right < len) {
            window[fruits[right]]++;

            // 如果窗口中水果类别个数小于等于2则添加
            if (window.size() > 2) {
                // 出现第三种水果类别
                // 首先计算此时的最大长度
                // 注意此时right是新的水果类别。因此计算长度需要从上一个开始
                int temp = right - left;
                temp > max_len ? max_len = temp : max_len;

                // 记录当前类别的上一个类别，也就是第二个类别
                int last_class = fruits[right - 1];
                // 找到第一个类别
                int first_class;
                for (int k = right - 1; k >= 0; k--) {
                    if (fruits[k] != last_class) {
                        first_class = k;
                        break;
                    } else left = k;
                }
                // 删除第一个类
                window.erase(fruits[first_class]);
            }

            right++;
        }
        int temp = right - left;
        temp > max_len ? max_len = temp : max_len;

        return max_len;
    }
};
// @lc code=end

