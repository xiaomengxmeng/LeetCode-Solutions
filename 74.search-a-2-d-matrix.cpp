/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30204
 *
 * [74] 搜索二维矩阵
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }

    //bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size(), n = matrix[0].size();
    //     int row = 0, clo = n - 1;
    //     while (row < m && clo >= 0)
    //     {
    //         if (matrix[row][clo] == target)
    //             return true;
    //         else if (matrix[row][clo] > target)
    //             clo--;
    //         else
    //             row++;
    //     }
    //     return false;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */

