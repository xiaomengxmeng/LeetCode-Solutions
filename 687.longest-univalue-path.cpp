/*
 * @lc app=leetcode.cn id=687 lang=cpp
 * @lcpr version=30204
 *
 * [687] 最长同值路径
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
class Solution {
public:
    int ans=0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode * root){
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(root->left && root->left->val != root->val)
            left = 0;
        if(root->right && root->right->val != root->val)
            right = 0;
        ans = max(ans,left+right);
        return max(left,right) + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,5,1,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,5,4,4,5]\n
// @lcpr case=end

 */

