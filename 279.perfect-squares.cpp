/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30204
 *
 * [279] 完全平方数
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
    int numSquares(int n) {
        vector dp(n+1, 0);
        for (int i = 1; i <= n;i++){
            dp[i] = i;
            for (int j = 1; j * j <= i;j++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */

