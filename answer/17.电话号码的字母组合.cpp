/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res;
    string path;
    vector<string> num_to_chars;
    
    Solution() : num_to_chars(10, "abc") {
        num_to_chars[3] = "def";
        num_to_chars[4] = "ghi";
        num_to_chars[5] = "jkl";
        num_to_chars[6] = "mno";
        num_to_chars[7] = "pqrs";
        num_to_chars[8] = "tuv";
        num_to_chars[9] = "wxyz";
    }

    void backtrace(const string &digits, const int start_index) {
        // 终止条件
        if (path.length() == digits.length()) {
            res.push_back(path);
            return;
        }

        // get index
        char c = digits[start_index];
        if (c < '2' || c > '9') std::exit(EXIT_FAILURE);
        int index = c - '0';

        for (int i = 0; i < num_to_chars[index].length(); ++i) {
            path += num_to_chars[index][i];
            backtrace(digits, start_index + 1);
            path = path.substr(0, path.length() - 1);
        }

    }

    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if (len == 0) return res;

        backtrace(digits, 0);

        return res;
    }
};
// @lc code=end

