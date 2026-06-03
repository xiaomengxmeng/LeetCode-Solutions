/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * [Review] Original completion: 2026-05-13
 * Key technique: Preorder root + inorder split
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size();i++)
        {
            in_map[inorder[i]] = i;
        }
        int pre_idx = 0;
        return dfs(preorder, in_map, pre_idx, 0, inorder.size() - 1);
    }
    TreeNode * dfs(vector<int>& preorder,unordered_map<int,int>&in_map,int &pre_idx,int in_left,int in_right){
        if(in_left>in_right)
            return nullptr;
        int root_val = preorder[pre_idx++];
        TreeNode *root = new TreeNode(root_val);
        int mid = in_map[root_val];
        root->left = dfs(preorder, in_map, pre_idx, in_left, mid - 1);
        root->right = dfs(preorder, in_map, pre_idx, mid + 1, in_right);
        return root;
    }
};
// @lc code=end

/*

// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
