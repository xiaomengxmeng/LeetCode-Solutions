/*
 * @lc app=leetcode.cn id=97 lang=cpp
 * @lcpr version=30204
 *
 * [97] 交错字符串
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
    // 动态规划法 
    /*
        状态定义：dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符是否能交错组成 s3 的前 i+j 个字符
        初始状态：dp[0][0] = true 表示 s1 和 s2 都为空时，能交错组成 s3 为空
        dp[i-1][j] 表示 s1 的前 i-1 个字符和 s2 的前 j 个字符是否能交错组成 s3 的前 i-1+j 个字符
        dp[i][j-1] 表示 s1 的前 i 个字符和 s2 的前 j-1 个字符是否能交错组成 s3 的前 i+j-1 个字符
        状态转移：dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1])
    */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), t = s3.length();
        if(m+n!=t)
            return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] =true;
        for (int i = 0; i <= m;i++){
            for (int j = 0; j <= n;j++){
                int p = i + j - 1;
                if(i>0){
                    dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if(j>0){
                    dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbcbcac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbbaccc"\n
// @lcpr case=end

// @lcpr case=start
// ""\n""\n""\n
// @lcpr case=end

 */

