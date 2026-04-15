/*
 * @lc app=leetcode.cn id=415 lang=cpp
 * @lcpr version=30204
 *
 * [415] 字符串相加
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
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string res = "";
        while (i>=0||j>=0||carry)
        {
            int sum = carry;
            if(i>=0)
                sum += num1[i--] - '0';
            if(j>=0)
                sum += num2[j--] - '0';
            carry = sum / 10;
            res += to_string(sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"123"\n
// @lcpr case=end

// @lcpr case=start
// "456"\n"77"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n"0"\n
// @lcpr case=end

 */

