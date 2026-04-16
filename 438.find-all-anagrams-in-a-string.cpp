/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30204
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        vector<int> count(26);
        for (char c : p)
            count[c - 'a']++;
        int p_count = 0;
        for (auto c : count)
        {
            if (c != 0)
                p_count++;
        }

        int matched = 0;

        for (int i = 0; i < p.size(); i++)
        {
            count[s[i] - 'a']--;
            if (count[s[i] - 'a'] == 0)
                matched++;
            else if (count[s[i] - 'a'] == -1)
                matched--;
        }
        if (matched == p_count)
            res.push_back(0);
        for (int i = p.size(); i < s.size(); i++)
        {

            count[s[i] - 'a']--;
            if (count[s[i] - 'a'] == 0)
                matched++; // 刚好匹配
            else if (count[s[i] - 'a'] == -1)
                matched--; // 从匹配变成不匹配
            // 离开字符 c
            count[s[i - p.size()] - 'a']++;
            if (count[s[i - p.size()] - 'a'] == 0)
                matched++; // 刚好匹配
            else if (count[s[i - p.size()] - 'a'] == 1)
                matched--; // 从匹配变成不匹配

            if (matched == p_count)
                res.push_back(i - p.size() + 1);
        }
        // if (matched == p_count)
        //     res.push_back(s.size() - p.size() + 1);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */
