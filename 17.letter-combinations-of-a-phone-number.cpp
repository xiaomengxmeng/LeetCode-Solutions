/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        //  映射下标:   2      3      4      5      6      7       8      9
        const string mapping[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string s = "";
        backtrack(res, s, 0, mapping, digits);
        return res;
    }
    void backtrack(vector<string> &res, string &s, int k, const string mapping[], const string &digits)
    {

        if (k == digits.size())
        {
            res.push_back(s);
            return;
        }
        for (char c : mapping[digits[k] - '2'])
        {
            s.push_back(c);
            backtrack(res, s, k + 1, mapping, digits);
            s.pop_back();
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
