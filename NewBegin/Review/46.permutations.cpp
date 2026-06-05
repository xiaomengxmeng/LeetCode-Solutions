/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] Permutations
 *
 * [Review] Original completion: 2026-05-28
 * Key technique: Backtrack + used array
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
#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtrack(nums, used, path, res);
        return res;
    }
    void backtrack(vector<int> & nums,vector<bool>&used,vector<int>&path,vector<vector<int>> &res){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size();i++){
            if(used[i])continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, res);
            used[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end
