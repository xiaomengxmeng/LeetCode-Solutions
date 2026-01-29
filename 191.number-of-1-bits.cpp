/*
 * @lc app=leetcode.cn id=191 lang=cpp
 * @lcpr version=30204
 *
 * [191] 位1的个数
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
    /*
        n =a*2^0+b*2^1+c*2^2+...
        统计n的二进制表示中1的个数
        第1次循环：
        n = 5 (101)
        n - 1 = 4 (100)
        n & (n-1) = 101 & 100 = 100 (4)  ← 消除了最右边的1
        res = 1

        第2次循环：
        n = 4 (100)
        n - 1 = 3 (011)
        n & (n-1) = 100 & 011 = 000 (0)  ← 又消除了一个1
        res = 2

        n = 0，循环结束
        返回 res = 2 ✅
    */
    int hammingWeight(int n) {
        int res = 0;
        while (n) {
            n &= n - 1;  // 消除 n 二进制中最右边的 1
            res++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 11\n
// @lcpr case=end

// @lcpr case=start
// 128\n
// @lcpr case=end

// @lcpr case=start
// 2147483645\n
// @lcpr case=end

 */

