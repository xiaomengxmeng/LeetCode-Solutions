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
使用 两个unordered_map进行双向确认 是为了确保 字符与单词之间的映射关系是严格的一一对应 （bijection），避免"多对一"的错误匹配。

### 为什么单向映射不够？
假设只使用一个 char_to_word （字符→单词）的映射，会存在**"不同字符映射到相同单词"**的漏洞：

反例 ：

- pattern: "abba"
- s: "dog dog dog dog" 单向map的错误判断过程：
1. 处理 a → dog ： char_to_word[a] = "dog" ✅
2. 处理 b → dog ： char_to_word[b] = "dog" ✅
3. 处理 b → dog ： char_to_word[b] 确实是 "dog" ✅
4. 处理 a → dog ： char_to_word[a] 确实是 "dog" ✅
单向map会认为匹配成功，但实际上 a 和 b 都映射到了同一个单词 "dog" ，违反了题目要求的**"每个字符对应唯一单词，每个单词也对应唯一字符"**的规则。

### 双向map的作用：确保一一对应
通过同时维护两个映射：

- char_to_word ：字符→单词（确保每个字符只对应一个单词）
- word_to_char ：单词→字符（确保每个单词只对应一个字符）
可以 双向验证 映射的唯一性：

同样反例的正确判断过程 ：

1. 处理 a → dog ：
   - char_to_word 中无 a ， word_to_char 中无 "dog" → 记录 a→dog 和 dog→a ✅
2. 处理 b → dog ：
   - char_to_word 中无 b ，但 word_to_char["dog"] 已经是 a （≠ b ） → 返回 false ❌
这样就能及时检测到"不同字符映射到相同单词"的错误情况。

### 总结：双向map的必要性
- 单向map ：只能保证"一个字符不会映射到多个单词"（单射）
- 双向map ：能保证"字符与单词之间严格一一对应"（双射）
题目要求的是 完全的模式匹配 （每个模式字符对应唯一单词，反之亦然），因此必须使用双向map进行双重验证。
*/


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

