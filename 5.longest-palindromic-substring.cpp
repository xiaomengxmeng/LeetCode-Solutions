/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s)
    {
        vector<int> res(2, 0);
        for (int i = 0; i < s.size(); i++)
        {
            auto t1 = expand(i, i, s);
            auto t2 = expand(i, i + 1, s);
            if (t1[1] - t1[0] > t2[1] - t2[0]) // 改这：t1[1]-t1[0] 就是长度
                res = t1[1] - t1[0] > res[1] - res[0] ? t1 : res;
            else
                res = t2[1] - t2[0] > res[1] - res[0] ? t2 : res;
        }
        return s.substr(res[0], res[1] - res[0] + 1);
    }
    vector<int> expand(int left, int right, string &s)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
