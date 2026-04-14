/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30204
 *
 * [155] 最小栈
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
class MinStack
{
public:
        stack<int> main_stack;
        stack<int> min_stack;
    MinStack()
    {

    }

    void push(int val)
    {
        this->main_stack.push(val);
        if ( this->min_stack.empty() ||  this->min_stack.top() >= val)
        {
             this->min_stack.push(val);
        }
    }

    void pop()
    {
        int top_val = this->main_stack.top();
        this->main_stack.pop();
        if ( top_val ==  this->min_stack.top())
        {
             this->min_stack.pop();
        }
    }

    int top()
    {
        return  this->main_stack.top();
    }

    int getMin()
    {
        return  this->min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */
