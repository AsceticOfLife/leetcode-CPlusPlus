/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    vector<string> path;

    // 判断区间[start_index, end_start]数字字符串是否为一个合法的点分十进制
    bool IsValid(const string &s, const int start_index, const int end_index) {
        int result = 0;
        int base = 1;
        
        // 不能含有前导零
        if (s[start_index] == '0' && end_index != start_index) return false;

        for (int i = end_index; i >= start_index; --i) {
            if (base >= 1000) return false; // 四位数不符合要求
            if (s[i] < '0' || s[i] > '9') return false;
            
            int temp = s[i] - '0';  // 没有权重的值
            result += (base * temp);
            base *= 10; // 基数增加
        }

        if (result >= 0 && result <= 255) return true;
        else return false;
    }

    void BackTrace(const string &s, const int start_index) {
        // 终止条件
        if (start_index >= s.length()) {
            // 4个字符串符合条件
            if (path.size() == 4) {
                string temp;
                for (int i = 0; i < 4; ++i) {
                    temp += path[i];
                    if (i < 3) temp += '.';
                }

                result.push_back(temp);
            } else {
                return;
            }
        }

        // 单层处理逻辑
        for (int i = start_index; i < s.length(); ++i) {
            if (IsValid(s, start_index, i)) {
                string temp = s.substr(start_index, i - start_index + 1);
                path.push_back(temp);

                // 剪枝：如果path中个数已经超过四个则后面再怎么分割都不合法
                // 应该回溯到上一层重新切割
                if (path.size() > 4) {
                    path.pop_back();
                    return;
                }
            } else {
                return;
            }

            BackTrace(s, i + 1);

            path.pop_back();
        }

    }

    vector<string> restoreIpAddresses(string s) {
        BackTrace(s, 0);

        return result;
    }
};
// @lc code=end

