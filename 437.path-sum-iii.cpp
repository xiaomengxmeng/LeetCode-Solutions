/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30204
 *
 * [437] 路径总和 III
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int count = 0;

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> map;
        map[0] = 1;
        dfs(root,0,targetSum,map);
        return count;
    }
    void dfs(TreeNode *root, long long parent_sum, int targetSum, unordered_map<long long,int> &map)
    {
        if(root ==nullptr)
            return;
        long long curr_sum = parent_sum + root->val;
        // 查找之前
        long long  need = curr_sum - targetSum;
        count += map[need]; // 查表：有多少条路径满足
        map[curr_sum]++;    // 记录当前前缀和
        dfs(root->left, curr_sum, targetSum,map);
        dfs(root->right, curr_sum, targetSum,map);
        map[curr_sum]--; // 回溯
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
