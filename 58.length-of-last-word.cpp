/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30204
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode.cn/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (48.50%)
 * Likes:    792
 * Dislikes: 0
 * Total Accepted:    757.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '"Hello World"'
 *
 * 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
 * 
 * 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "Hello World"
 * 输出：5
 * 解释：最后一个单词是“World”，长度为 5。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "   fly me   to   the moon  "
 * 输出：4
 * 解释：最后一个单词是“moon”，长度为 4。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "luffy is still joyboy"
 * 输出：6
 * 解释：最后一个单词是长度为 6 的“joyboy”。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅有英文字母和空格 ' ' 组成
 * s 中至少存在一个单词
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
    // 从后往前遍历，跳过空格，记录最后一个单词的长度
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        int res=0;
        while(i>=0&& s[i]==' ')  i--;
        while(i>=0&& s[i]!=' ') 
        {
            res++;
            i--;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */

