/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        backtrack(res, s, n, n);
        return res;
    }
    // 回溯函数 left right 分别表示剩余的左括号和右括号数量
    void backtrack(vector<string> &res, string &s, int left, int right){
        if(left==0&&right==0){
            res.push_back(s);
            return;
        }
        if(left>0){
            s.push_back('(');
            backtrack(res, s, left-1, right);
            s.pop_back();
        }
        if(right>left){
            s.push_back(')');
            backtrack(res, s, left, right-1);
            s.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

