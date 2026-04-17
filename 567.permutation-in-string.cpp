/*
 * @lc app=leetcode.cn id=567 lang=cpp
 * @lcpr version=30204
 *
 * [567] 字符串的排列
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
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        vector<int> count(26);
        int match = 0;
        for (auto c : s1)
            count[c - 'a']++;
        int s1_count = 0;
        for (auto i : count)
            if (i != 0)
                s1_count++;
        for (int i = 0; i < s1.size(); i++)
        {
            // 初始进入字符
            count[s2[i] - 'a']--;
            if (count[s2[i] - 'a'] == 0)
                match++;
            else if (count[s2[i] - 'a'] == -1)
                match--;
        }
        if (match == s1_count)
            return true;
        for (int i = s1.size(); i < s2.size(); i++)
        {
            // 进入字符
            count[s2[i] - 'a']--;
            if (count[s2[i] - 'a'] == 0)
                match++;
            else if (count[s2[i] - 'a'] == -1)
                match--;
            // 离开字符
            count[s2[i - s1.size()] - 'a']++;
            if (count[s2[i - s1.size()] - 'a'] == 0)
                match++;
            else if (count[s2[i - s1.size()] - 'a'] == 1)
                match--;
            if (match == s1_count)
                return true;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */
