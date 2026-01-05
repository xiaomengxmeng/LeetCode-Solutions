/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(path,target,candidates,0,res);
        return res;
    }
    void dfs(vector<int> &path,int last,vector<int>& candidates,int start,vector<vector<int>> &res){
        if(last ==0){
            res.push_back(path);
            
        }
        for(int i=start;i<candidates.size();i++){
            if(last-candidates[i]>=0){
                path.push_back(candidates[i]);
                dfs(path,last-candidates[i],candidates,i,res);
                path.pop_back();
            }
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

