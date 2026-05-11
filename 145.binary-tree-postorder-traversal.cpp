/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30204
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {

        vector<int> vec;
        if (!root)
            return vec;
        stack<TreeNode *> st;
        // // 前序迭代
        // st.push(root);
        // while (!st.empty()) {
        //     cur = st.top(); st.pop();
        //     vec.push_back(cur->val);     // 处理根
        //     if (cur->right) st.push(cur->right);  // 右
        //     if (cur->left)  st.push(cur->left);   // 左
        // }
        // vec = 根→左→右
        // 后序迭代
        TreeNode *cur = root;
        st.push(root);
        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            vec.push_back(cur->val); // 处理根
            if (cur->left)
                st.push(cur->left); // 左
            if (cur->right)
                st.push(cur->right); // 右
        }
        // vec = 左→右→根
        // 反转 vec 即为 后序遍历
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
