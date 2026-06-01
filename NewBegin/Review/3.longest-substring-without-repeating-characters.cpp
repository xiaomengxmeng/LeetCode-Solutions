/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30204
 *
 * [3] Longest Substring Without Repeating Characters
 * 
 * [Review] Original completion: 2026-04-16
 * Key technique: Sliding window + freq array
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
    int lengthOfLongestSubstring(string s){
        int left = 0, ans = 0;
        vector<int> freq(128, 0);
        for (int right = 0; right < s.size();right++){
            freq[s[right]]++;   //右指针字符入窗口
            while(freq[s[right]]>1){ // 出现重复
                freq[s[left]]--;  //左指针字符出窗口
                left++;         //左指针右移
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    // int lengthOfLongestSubstring(string s) {
    //     int left = 0, ans = 0;
    //     vector<int> freq(128, -1);
    //     for (int right = 0; right < s.size();right++){
    //         if(freq[s[right]]>=left){
    //             left = freq[s[right]] + 1;
    //         }
    //         freq[s[right]] = right;
    //         ans = max(ans, right - left + 1);
    //     }
    //     return ans;
    // }
};
// @lc code=end

/*

// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
