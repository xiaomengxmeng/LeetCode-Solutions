/*
 * @lc app=leetcode.cn id=461 lang=cpp
 * @lcpr version=30204
 *
 * [461] 汉明距离
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
        汉明距离 是指两个整数之间的二进制位不同的位置的数目。
        给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

    */
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x!=0 || y!=0){
            res += (x&1) ^ (y&1);  //比较当前位是否不同
            // 右移一位，继续比较下一位
            x >>= 1; 
            y >>= 1;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n4\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n
// @lcpr case=end

 */

