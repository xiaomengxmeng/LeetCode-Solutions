/*
 * @lc app=leetcode.cn id=756 lang=cpp
 * @lcpr version=30204
 *
 * [756] 金字塔转换矩阵
 *
 * https://leetcode.cn/problems/pyramid-transition-matrix/description/
 *
 * algorithms
 * Medium (50.73%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 26.4K
 * Testcase Example:  '"BCD"\n["BCC","CDE","CEA","FFF"]'
 *
 * 你正在把积木堆成金字塔。每个块都有一个颜色，用一个字母表示。每一行的块比它下面的行 少一个块 ，并且居中。
 * 
 * 为了使金字塔美观，只有特定的 三角形图案 是允许的。一个三角形的图案由 两个块 和叠在上面的 单个块 组成。模式是以三个字母字符串的列表形式
 * allowed 给出的，其中模式的前两个字符分别表示左右底部块，第三个字符表示顶部块。
 * 
 * 
 * 例如，"ABC" 表示一个三角形图案，其中一个 “C” 块堆叠在一个 'A' 块(左)和一个 'B' 块(右)之上。请注意，这与 "BAC"
 * 不同，"B" 在左下角，"A" 在右下角。
 * 
 * 
 * 你从作为单个字符串给出的底部的一排积木 bottom 开始，必须 将其作为金字塔的底部。
 * 
 * 在给定 bottom 和 allowed 的情况下，如果你能一直构建到金字塔顶部，使金字塔中的 每个三角形图案 都是在 allowed 中的，则返回
 * true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
 * 输出：true
 * 解释：允许的三角形图案显示在右边。
 * 从最底层(第 3 层)开始，我们可以在第 2 层构建“CE”，然后在第 1 层构建“A”。
 * 金字塔中有三种三角形图案，分别是 “BCC”、“CDE” 和 “CEA”。都是允许的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
 * 输出：false
 * 解释：允许的三角形图案显示在右边。
 * 从最底层(即第 4 层)开始，创造第 3 层有多种方法，但如果尝试所有可能性，你便会在创造第 1 层前陷入困境。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= bottom.length <= 6
 * 0 <= allowed.length <= 216
 * allowed[i].length == 3
 * 所有输入字符串中的字母来自集合 {'A', 'B', 'C', 'D', 'E', 'F'}。
 * allowed 中所有值都是 唯一的
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
    /*bottom[i]bottom[i+1]  allowed[i].[0]==bottom[i]&&allowed[i].[1]==bottom[i+1]
        allowed[i].[2] 是可选的顶部块
        遍历完 找出所有可选的顶部块
        继续对bottom[i+1]bottom[i+2] 进行相同操作
        存储所有allowed的规则，便于查找当前可使用的顶部字符
        每次构建时都有判断是否满足allowed的规则，
        如果不满足 则返回false
        当所有字符都不满足时，返回递归的上一层 重新选择顶部字符
        终止条件 当最后只剩一块时构建好了金字塔

    */
    /*
    优化方案思路：
    1. 字符映射：将A-F映射为0-5的数字，减少内存占用
    2. 位运算优化：使用位掩码表示可能的顶部字符集合
       - 例如，0b101表示可能是A(0)或C(2)
    3. 记忆化搜索：避免重复计算相同的层
    4. 利用字符集小的特性（仅6个字符），可以使用更紧凑的数据结构
    */
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // 1. 字符映射：A-F -> 0-5
        auto charToInt = [](char c) { return c - 'A'; };
        
        // 2. 规则存储：使用三维数组 rules[left][right] = mask
        //    其中mask的第k位为1表示left和right可以组成k对应的字符
        vector<vector<int>> rules(6, vector<int>(6, 0));
        for (const string& a : allowed) {
            int left = charToInt(a[0]);
            int right = charToInt(a[1]);
            int top = charToInt(a[2]);
            rules[left][right] |= (1 << top);
        }
        
        // 3. 将bottom转换为数字数组，便于后续处理
        vector<int> bottomNums;
        for (char c : bottom) {
            bottomNums.push_back(charToInt(c));
        }
        
        // 4. 记忆化搜索：memo[layer][i]表示当前层第i个位置的可能字符掩码
        //    这里使用unordered_map作为简单实现
        unordered_map<string, bool> memo;
        
        // 5. 调用递归函数
        return canBuild(bottomNums, rules, memo);
    }
    
    // 将当前层的数字数组转换为字符串，作为记忆化的键
    string getKey(const vector<int>& layer) {
        string key;
        for (int num : layer) {
            key += to_string(num);
        }
        return key;
    }
    
    // 记忆化搜索函数
    bool canBuild(const vector<int>& current, vector<vector<int>>& rules, 
                 unordered_map<string, bool>& memo) {
        // 终止条件：到达金字塔顶部
        if (current.size() == 1) {
            return true;
        }
        
        // 检查是否已经计算过当前层
        string key = getKey(current);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        // 检查当前层的所有相邻字符对是否都有规则
        for (int i = 0; i < current.size() - 1; ++i) {
            int left = current[i];
            int right = current[i + 1];
            if (rules[left][right] == 0) {
                return memo[key] = false; // 没有规则，无法构建
            }
        }
        
        // 生成所有可能的上一层组合
        vector<int> next(current.size() - 1);
        bool result = backtrack(0, current, next, rules, memo);
        
        // 记忆化结果
        return memo[key] = result;
    }
    
    // 回溯函数：生成所有可能的上一层组合
    bool backtrack(int index, const vector<int>& current, vector<int>& next, 
                  vector<vector<int>>& rules, unordered_map<string, bool>& memo) {
        // 终止条件：已经生成了完整的上一层
        if (index == next.size()) {
            return canBuild(next, rules, memo);
        }
        
        // 获取当前相邻字符对的可能顶部字符掩码
        int left = current[index];
        int right = current[index + 1];
        int mask = rules[left][right];
        
        // 尝试所有可能的顶部字符
        for (int i = 0; i < 6; ++i) {
            if (mask & (1 << i)) { // 检查第i位是否为1
                next[index] = i;
                if (backtrack(index + 1, current, next, rules, memo)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "BCD"\n["BCC","CDE","CEA","FFF"]\n
// @lcpr case=end

// @lcpr case=start
// "AAAA"\n["AAB","AAC","BCD","BBE","DEF"]\n
// @lcpr case=end

 */

