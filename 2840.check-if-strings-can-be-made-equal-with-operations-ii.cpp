/*
 * @lc app=leetcode.cn id=2840 lang=cpp
 * @lcpr version=30204
 *
 * [2840] 判断通过操作能否让字符串相等 II
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
    给你两个字符串 s1 和 s2 ，两个字符串长度都为 n ，且只包含 小写 英文字母。
    你可以对两个字符串中的 任意一个 执行以下操作 任意 次：
    选择两个下标 i 和 j ，满足 i < j 且 j - i 是 偶数，
    然后 交换 这个字符串中两个下标对应的字符。
    判断两个字符串的奇数子串和偶数子串的字母组成是否相等。
    */
bool checkStrings(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    
    string evenS1, evenS2, oddS1, oddS2;
    for (int i = 0; i < s1.size(); i++) {
        if (i % 2 == 0) {
            evenS1 += s1[i];
            evenS2 += s2[i];
        } else {
            oddS1 += s1[i];
            oddS2 += s2[i];
        }
    }
    
    return checkSubString(evenS1, evenS2) && checkSubString(oddS1, oddS2);
}

bool checkSubString(string s1, string s2) {
    int count[26] = {0};
    for (char c : s1) {
        count[c - 'a']++;
    }
    for (char c : s2) {
        count[c - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}
};
// @lc code=end



/*
// @lcpr case=start
// "abcdba"\n"cabdab"\n
// @lcpr case=end

// @lcpr case=start
// "abe"\n"bea"\n
// @lcpr case=end

 */

