/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=30204
 *
 * [100] 相同的树
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
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if (!p && !q) return true;
    //     if (!p || !q) return false;
    //     return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> qp, qq;
    qp.push(p); qq.push(q);
    while (!qp.empty() && !qq.empty()) {
        auto n1 = qp.front(); qp.pop();
        auto n2 = qq.front(); qq.pop();
        if (!n1 && !n2) continue;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        qp.push(n1->left); qp.push(n1->right);
        qq.push(n2->left); qq.push(n2->right);
    }
    return qp.empty() && qq.empty();
}
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */

