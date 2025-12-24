/*
 * @lc app=leetcode.cn id=290 lang=cpp
 * @lcpr version=30204
 *
 * [290] 单词规律
 *
 * https://leetcode.cn/problems/word-pattern/description/
 *
 * algorithms
 * Easy (45.39%)
 * Likes:    726
 * Dislikes: 0
 * Total Accepted:    257.5K
 * Total Submissions: 567.4K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。具体来说：
 * 
 * 
 * pattern 中的每个字母都 恰好 映射到 s 中的一个唯一单词。
 * s 中的每个唯一单词都 恰好 映射到 pattern 中的一个字母。
 * 没有两个字母映射到同一个单词，也没有两个单词映射到同一个字母。
 * 
 * 
 * 
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", s = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", s = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", s = "dog cat cat dog"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= pattern.length <= 300
 * pattern 只包含小写英文字母
 * 1 <= s.length <= 3000
 * s 只包含小写英文字母和 ' '
 * s 不包含 任何前导或尾随对空格
 * s 中每个单词都被 单个空格 分隔
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
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        if(pattern.size() != words.size())
            return false;
        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;
        for(int i = 0; i < pattern.size(); i++){
            char c = pattern[i];
            string w = words[i];
            if(char_to_word.count(c) && char_to_word[c] != w)
                return false;
            if(word_to_char.count(w) && word_to_char[w] != c)
                return false;
            char_to_word[c] = w;
            word_to_char[w] = c;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */

