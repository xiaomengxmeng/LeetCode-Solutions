/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30204
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (59.77%)
 * Likes:    1660
 * Dislikes: 0
 * Total Accepted:    761.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是 平衡二叉树  
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 <= Node.val <= 10^4
 *
 *
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    // 递归解法
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        else
        {
            return max(leftHeight, rightHeight) + 1;
        }
    }
    bool isBalanced(TreeNode *root)
    {
        // return getHeight(root) != -1;
        if (root == nullptr)
            return true;
        stack<TreeNode *> stk;
        unordered_map<TreeNode *, int> nodeHeight; // 存储每个节点的高度
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *curr = stk.top();
            if ((curr->left == nullptr || nodeHeight.count(curr->left)) &&
                (curr->right == nullptr || nodeHeight.count(curr->right)))
            {
                stk.pop();
                int leftH = curr->left ? nodeHeight[curr->left] : 0;
                int rightH = curr->right ? nodeHeight[curr->right] : 0;
                if (abs(leftH - rightH) > 1)
                    return false;
                nodeHeight[curr] = max(leftH, rightH) + 1;
            }else{
                // 后序遍历，先遍历左右子树，再遍历当前节点
                if(curr->right)
                    stk.push(curr->right);
                if(curr->left)
                    stk.push(curr->left);
            }


        }
        return true;
    }
};
/*
在非递归后序遍历中 先压右子树，再压左子树 ，是由 栈的"后进先出(LIFO)"特性 决定的，目的是为了确保最终处理顺序符合后序遍历的要求（左→右→根）。

### 核心原理：栈的LIFO特性与遍历顺序的匹配
后序遍历要求的处理顺序是： 左子树 → 右子树 → 根节点

而栈是"后进先出"的，即 后压入的元素会先弹出 。因此：

- 为了让 左子树先被处理 ，需要 后压入左子树 （这样左子树会先弹出）
- 为了让 右子树后于左子树处理 ，需要 先压入右子树 （这样右子树会后弹出）
### 具体例子演示
假设树结构为：

```
    A
   / \
  B   C
```
后序遍历期望顺序： B → C → A
 先压右子树的情况（正确）：
1. 初始栈： [A]
2. 处理A时（左右子树未处理），先压右子树C，再压左子树B → 栈变为： [A, C, B]
3. 弹出B处理 → 处理顺序： [B]
4. 弹出C处理 → 处理顺序： [B, C]
5. 弹出A处理 → 处理顺序： [B, C, A] ✅（符合后序遍历） 先压左子树的情况（错误）：
1. 初始栈： [A]
2. 处理A时，先压左子树B，再压右子树C → 栈变为： [A, B, C]
3. 弹出C处理 → 处理顺序： [C]
4. 弹出B处理 → 处理顺序： [C, B]
5. 弹出A处理 → 处理顺序： [C, B, A] ❌（变成了"右→左→根"，不是后序）
*/
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
