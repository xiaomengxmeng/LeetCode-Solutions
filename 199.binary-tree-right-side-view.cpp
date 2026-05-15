/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30204
 *
 * [199] 二叉树的右视图
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
public:
    // BFS层序
    //  vector<int> rightSideView(TreeNode* root) {
    //      vector<int> ans;
    //      if(!root)
    //          return ans;
    //      queue<TreeNode *> q;
    //      q.push(root);
    //      while (!q.empty())
    //      {
    //          int size = q.size();
    //          for (int i = 0; i < size; i++){
    //              TreeNode *node = q.front();
    //              q.pop();
    //              if(i==size-1)
    //                  ans.push_back(node->val);
    //              if(node->left)
    //                  q.push(node->left);
    //               if(node->right)
    //                  q.push(node->right);
    //          }
    //      }
    //      return ans;
    //      }
    // DFS
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
    // 辅助函数签名
    void dfs(TreeNode *root, int depth, vector<int> &ans) {
        if(root==nullptr)
            return;
        // 先右后左，depth 从 0 开始
        if(depth ==ans.size()) {
            ans.push_back(root->val);
        }
        dfs(root->right, depth + 1, ans);
        dfs(root->left, depth + 1, ans);
    }
};
    // @lc code=end

    /*
    // @lcpr case=start
    // [1,2,3,null,5,null,4]\n
    // @lcpr case=end

    // @lcpr case=start
    // [1,2,3,4,null,null,null,5]\n
    // @lcpr case=end

    // @lcpr case=start
    // [1,null,3]\n
    // @lcpr case=end

    // @lcpr case=start
    // []\n
    // @lcpr case=end

     */
