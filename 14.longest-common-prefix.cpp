/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30204
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (45.05%)
 * Likes:    3432
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 如果非空，则仅由小写英文字母组成
 * 
 * 
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
    // 方法1：水平扫描
    // 时间复杂度：O(mn)，其中 m 是字符串数组中的字符串的平均长度，n 是字符串的数量。
    // 空间复杂度：O(1)。
    // 思路：从前往后遍历每个字符串的每个字符，直到找到一个字符不匹配，或者遍历完所有字符串。
    // 如果遍历完所有字符串，说明所有字符串的前缀都相同，返回第一个字符串即可。
    // 如果找到一个字符不匹配，说明公共前缀的长度为 j，返回 prefix 的前 j 个字符即可。
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            // 遍历每个字符串的每个字符，直到找到一个字符不匹配，或者遍历完所有字符串
            while(j<prefix.size()&&j<strs[i].size()&&prefix[j]==strs[i][j])
            {
                j++;
            }
            prefix=prefix.substr(0,j);
            if(prefix.empty()) return "";
        }
        return prefix;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

