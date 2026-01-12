/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30204
 *
 * [49] 字母异位词分组
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
    输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

    输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
    哈希 key 为排序后的字符串 values 为字母异位词列表

    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string str:strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it=map.begin();it!=map.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

