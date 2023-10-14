/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    // 暴力解法
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int k = 1;
        // 外层循环遍历第一个数组的元素作为起点
        for (int i = 0; i < nums1.size(); i++) {
            // 中间循环遍历第二个数组的每一个元素作为起点
            for (int j = 0; j < nums2.size(); j += 1) {
                if (nums1[i] != nums2[j]) continue; // 如果不相等直接跳过

                // 内层循环向后依次比较二者后续元素
                k = 1;
                while (i + k < nums1.size() && j + k < nums2.size() && nums1[i + k] == nums2[j + k])
                    k++;
                // 最终i+k和j+k下标对应的两个元素是不相等的
                // 记录此时长度
                result < k ? result = k : result;
            }
        }

        return result;
    }
};
// @lc code=end

