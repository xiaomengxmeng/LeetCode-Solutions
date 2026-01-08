/*
 * @lc app=leetcode.cn id=38 lang=cpp
 * @lcpr version=30204
 *
 * [38] 外观数列
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
    countAndSay(1) = "1"
    countAndSay(n) 是 countAndSay(n-1) 的行程长度编码。
    行程长度编码（RLE）是一种字符串压缩方法，
    其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数（运行长度）和字符的序列。
    例如，要压缩字符串 "3322251" ，我们将 "33" 用 "23" 替换，将 "222" 用 "32" 替换，将 "5" 用 "15" 替换并将 "1" 用 "11" 替换。
    因此压缩字符串变为 "23321511"。
    给定一个整数 n ，返回外观数列的第 n 个元素。
    递推计算countAndSay(n);
    每次迭代，我们将当前字符串 s 转换为行程长度编码字符串 t。
    具体来说，我们从左到右遍历 s，统计连续相同字符的数量，
    并将数量和字符拼接成一个字符串，
    最后将所有这样的字符串拼接起来即可。
    */
    string countAndSay(int n) {
        if(n==1)
            return "1";
        // 递归计算countAndSay(n-1);
        string s = countAndSay(n - 1);
        string res = "";
        for (int i = 0; i < s.size();i++){
            int j = i;
            while(j<s.size()&&s[j]==s[i])
                j++; // 统计连续相同字符的数量
            res += to_string(j - i) + s[i]; // 拼接数量和字符
            i = j - 1;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

