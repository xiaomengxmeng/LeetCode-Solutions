/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
 *
 * [复习] 原完成日期：2026-04-14
 * 核心技巧：栈匹配
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
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> m = {
            {')', '('},{']', '['}, {'}', '{'}};
        for (auto c : s)
        {
            if (m.count(c))
            {
                if (st.empty() || st.top() != m[c])
                    return false;
                else
                    st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        return st.empty();
    }
    // {
    //     stack<char> st;
    //     for (auto c : s)
    //     {
    //         if (c == '(' || c == '[' || c == '{')
    //             st.push(c);
    //         else
    //         {
    //             if(st.empty()) return false;
    //             switch (c)
    //             {
    //             case '}':
    //                 if (st.top() == '{')
    //                     st.pop();
    //                 else
    //                 {
    //                     return false;
    //                 }
    //                 break;
    //             case ']':
    //                 if (st.top() == '[')
    //                     st.pop();
    //                 else
    //                 {
    //                     return false;
    //                 }
    //                 break;
    //             case ')':
    //                 if (st.top() == '(')
    //                     st.pop();
    //                 else
    //                 {
    //                     return false;
    //                 }
    //                 break;

    //             default:
    //                 break;
    //             }
    //         }
    //     }
    //     if(st.empty()) return true;
    //     return false;
    // }
};
// @lc code=end
/*

// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */
