/*
 * @lc app=leetcode.cn id=89 lang=cpp
 * @lcpr version=30204
 *
 * [89] 格雷编码
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
    /*
    第一个 第一个整数是 0  最后一个数的二进制是只有一个 1 其他全0的
    一个整数在序列中出现 不超过一次
    每对 相邻 整数的二进制表示 恰好一位不同 ，且
    第一个 和 最后一个 整数的二进制表示 恰好一位不同
*/
    vector<int> grayCode(int n)
    {
        vector<int> res;
        for(int i=0;i<(1<<n);i++){
            res.push_back(i^(i>>1));
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
