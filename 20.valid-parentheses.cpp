/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
        stack<char> stack;
        for (char c : s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                stack.push(c);
            }
            if(stack.empty())
                return false;
            if (c == '}')
            {   
                if (stack.top() == '{')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            if (c == ']')
            {
                if (stack.top() == '[')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            if (c == ')')
            {
                if (stack.top() == '(')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(stack.empty()) return true;
        return false;
    }
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

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */
