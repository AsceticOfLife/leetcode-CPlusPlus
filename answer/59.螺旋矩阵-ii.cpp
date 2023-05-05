/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1; // 矩阵中的数字，不断递增到n的平方
        int limit = n / 2; // 循环次数，因为一次外圈就会填上2个数字
        int offset = 0; // 偏移量，每次进入内圈循环之后起点和结束必须加上或者减去偏移量
        
        while (offset < limit) {
            // 行起点和列起点
            int x = 0 + offset;
            int y = 0 + offset;
            // 从左到右填充上行
            for (; y < n - 1 - offset; y++) 
                res[x][y] = num++;
            // 此时循环结束，x为本次最外侧没有填充的行元素
            // 从上到小填充右列
            for (; x < n - 1 - offset; x++)
                res[x][y] = num++;
            // 此时循环结束，y指向本次最右侧最下面的列元素
            // 从右向左填充下行
            for (; y > 0 + offset; y--) 
                res[x][y] = num++;
            for (; x > 0 + offset; x--)
                res[x][y] = num++;
            
            // 一圈循环完毕，偏移量增加。即表示向内一圈
            offset++;
        }
        if (n % 2 == 1) res[limit][limit] = num++;

        return res;
    }
};
// @lc code=end

