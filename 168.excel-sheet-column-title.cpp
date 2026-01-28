/*
 * @lc app=leetcode.cn id=168 lang=cpp
 * @lcpr version=30204
 *
 * [168] Excel 表列名称
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
    /*
    给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
    1 -> A
    27 -> AA
    char c = 'A' + (columnNumber - 1) % 26;
    ...
    */
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber>0){
            columnNumber--;
            char c = columnNumber % 26 + 'A';
            columnNumber /= 26;
            res += c;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 28\n
// @lcpr case=end

// @lcpr case=start
// 701\n
// @lcpr case=end

// @lcpr case=start
// 2147483647\n
// @lcpr case=end

 */

