/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30204
 *
 * [494] 目标和
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
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum || (target + sum) % 2 != 0) return 0;
        int P = (target + sum) / 2;
        if (P < 0) return 0;

        vector<int> dp(P + 1, 0);
        dp[0] = 1;
        for (int num : nums)
            for (int j = P; j >= num; j--)
                dp[j] += dp[j - num];
        return dp[P];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
