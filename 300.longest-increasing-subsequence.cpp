/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30204
 *
 * [300] 最长递增子序列
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
    int lengthOfLIS(vector<int>& nums) {
        // === O(n²) DP ===
        // int n = nums.size(), ans = 1;
        // vector<int> dp(n, 1);
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[j] < nums[i])
        //             dp[i] = max(dp[j] + 1, dp[i]);
        //     }
        //     ans = max(dp[i], ans);
        // }
        // return ans;

        // === O(n log n) 贪心 + 二分 ===
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end())
                tails.push_back(num);
            else
                *it = num;
        }
        return tails.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */
