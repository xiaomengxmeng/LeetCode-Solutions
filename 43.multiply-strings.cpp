/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30204
 *
 * [43] 字符串相乘
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
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
       // 阶段 1：累加所有乘积
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] += mul;
            }
        }
        
        // 阶段 2：统一处理进位（从右到左）
        int carry = 0;
        for (int i = m + n - 1; i >= 0; i--) {
            int temp = res[i] + carry;
            res[i] = temp % 10;
            carry = temp / 10;
        }
        
        string ans="";
        for(int i=0;i<res.size();i++)
        {
            if(i==0&&res[i]==0) continue;
            ans+=to_string(res[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */

