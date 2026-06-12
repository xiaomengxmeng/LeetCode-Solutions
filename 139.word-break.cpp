/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int maxSize = 0;
        for(string word:wordDict){
            set.insert(word);
            maxSize = max(maxSize, (int)word.size());
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 0; i < dp.size();i++){
            for (int j = 0; j < i;j++){
                if((i-j)>maxSize) continue;
                if(dp[j]==true&&set.find(s.substr(j,i-j))!=set.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

