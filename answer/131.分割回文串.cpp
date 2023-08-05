/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    // 判断是否为回文字符串
    bool IsPlaindrome(const string &s, const int start_index, int end_index) {
        for (int i = start_index, j = end_index; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }

        return true;
    }

    void BackTrace(const string &s, const int start_index) {
        // 终止条件
        if (start_index >= s.size()) {
            result.push_back(path);   
            return;
        }
        // 单层逻辑
        for (int i = start_index; i < s.size(); ++i) {
            if (IsPlaindrome(s, start_index, i) == true) {
                // 获取[start_index, i]之间的字串
                string temp = s.substr(start_index, i - start_index + 1);
                path.push_back(temp);
            } else {
                continue; // 不是回文，剩余都跳过
            }

            BackTrace(s, i + 1);

            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        BackTrace(s, 0);

        return result;
    }
};
// @lc code=end

