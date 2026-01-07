/*
 * @lc app=leetcode.cn id=95 lang=cpp
 * @lcpr version=30204
 *
 * [95] 不同的二叉搜索树 II
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
    /*
    根据二叉搜索树的性质，根节点的值大于左子树的所有节点的值，小于右子树的所有节点的值。
    因此，我们可以枚举根节点的值，然后递归构造左子树和右子树。
    根节点的值的范围是 [1, n]，因此我们可以枚举根节点的值，然后递归构造左子树和右子树。
    左子树的节点值的范围是 [1, root-1]，右子树的节点值的范围是 [root+1, n]。
    返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树
    */
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {};
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start>end)
        {
            return {nullptr};
        }
        vector<TreeNode *> res;
        for (int i = start; i <= end;i++){
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for (auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

