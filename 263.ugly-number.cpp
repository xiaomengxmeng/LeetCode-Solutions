/*
 * @lc app=leetcode.cn id=263 lang=cpp
 * @lcpr version=30204
 *
 * [263] 丑数
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
class Solution
{
public:
    /*
        丑数 就是只包含质因数 2、3 和 5 的 正 整数。
    */
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        // 依次除以所有质因数2、3、5
        for (int factor : {2, 3, 5})
        {
            while (n % factor == 0)
            {
                n /= factor;
            }
        }
        return n == 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */
