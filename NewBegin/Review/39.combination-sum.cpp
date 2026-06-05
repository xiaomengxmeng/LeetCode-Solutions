/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] Combination Sum
 *
 * [Review] Original completion: 2026-05-28
 * Key technique: Backtrack + sort prune
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
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end()); // 先排序
        backtrack(candidates, 0, 0, path, res, target);
        return res;
    }
    void backtrack(vector<int> &candidates, int start, int sum, vector<int> &path, vector<vector<int>> &res, int target)
    {
        if (sum == target)
        {
            res.push_back(path);
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (sum + candidates[i] > target)
                break;
            path.push_back(candidates[i]);
            backtrack(candidates, i, sum + candidates[i], path, res, target);
            path.pop_back();
        }
    }
};
// @lc code=end
