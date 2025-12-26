# 二叉树深度问题总结

## 1. 概述

本文档总结了LeetCode中两个经典的二叉树深度问题：

- 104. 二叉树的最大深度
- 111. 二叉树的最小深度

## 2. 104. 二叉树的最大深度

### 2.1 问题描述

给定一个二叉树的根节点 `root`，返回其最大深度。二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。

**示例：**

```
输入：root = [3,9,20,null,null,15,7]
输出：3
解释：该二叉树的结构如下，最大深度为3层
    3
   / \n  9  20
    /  \
   15   7
```

### 2.2 解决方案

采用**递归深度优先搜索（DFS）**的方法：

```cpp
int depth(TreeNode * root) {
    if(root == nullptr)
        return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return max(leftDepth, rightDepth) + 1;
}
```

### 2.3 算法分析

- **递归思想**：当前节点的深度等于左右子树深度的最大值加1
- **边界条件**：空节点的深度为0
- **时间复杂度**：O(n)，每个节点仅访问一次
- **空间复杂度**：O(h)，h为树的高度，最坏情况为O(n)（树退化为链表）

## 3. 111. 二叉树的最小深度

### 3.1 问题描述

给定一个二叉树的根节点 `root`，找出其最小深度。最小深度是指从根节点到最近叶子节点的最短路径上的节点数量。

**注意**：叶子节点是指没有子节点的节点。

**示例1：**

```
输入：root = [3,9,20,null,null,15,7]
输出：2
解释：该二叉树的最小深度为2层（3→9）
```

**示例2：**

```
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
解释：该二叉树只有右子树，最小深度为5层
```

### 3.2 解决方案

同样采用**递归DFS**方法，但需要处理特殊情况：

```cpp
int minDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return 1;
    int leftDepth=minDepth(root->left);
    int rightDepth=minDepth(root->right);
    if(root->left == nullptr)
        return rightDepth + 1;
    if(root->right == nullptr)
        return leftDepth + 1;
    return min(leftDepth, rightDepth) + 1;
}
```

### 3.3 算法分析

- **递归思想**：当前节点的最小深度等于左右子树最小深度的最小值加1
- **特殊情况处理**：
  - 当节点为叶子节点时，深度为1
  - 当节点只有左子树时，最小深度为右子树深度加1
  - 当节点只有右子树时，最小深度为左子树深度加1
- **时间复杂度**：O(n)，每个节点仅访问一次
- **空间复杂度**：O(h)，h为树的高度，最坏情况为O(n)（树退化为链表）

## 4. 两个问题的对比分析

### 4.1 相似点

- **问题类型**：均为二叉树深度问题，属于二叉树遍历范畴
- **解决方案**：都采用递归DFS方法
- **时间复杂度**：均为O(n)
- **空间复杂度**：均为O(h)

### 4.2 不同点

- **定义差异**：
  - 最大深度：到最远叶子节点的最长路径
  - 最小深度：到最近叶子节点的最短路径
- **处理逻辑**：
  - 最大深度：简单取左右子树深度的最大值
  - 最小深度：需要处理单侧子树为空的特殊情况
- **边界情况**：
  - 最大深度：空树返回0
  - 最小深度：空树返回0，单侧子树需要特殊处理

### 4.3 关键洞察

- **叶子节点的重要性**：两个问题都依赖于叶子节点的定义
- **递归的终止条件**：需要根据问题特点设计合适的终止条件
- **单侧子树的处理**：最小深度问题必须处理单侧子树为空的情况，否则会得到错误结果

## 5. 代码优化建议

### 5.1 迭代版本实现

递归版本虽然简洁，但在树深度较大时可能导致栈溢出。可以使用迭代方法（如层次遍历BFS）来避免：

**最大深度的迭代实现：**

```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        depth++;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}
```

**最小深度的迭代实现：**

```cpp
int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        depth++;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left && !node->right) return depth;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}
```

### 5.2 优化点

- 迭代版本使用队列实现BFS，避免了递归栈溢出的风险
- 最小深度的迭代版本在找到第一个叶子节点时即可返回，可能提前结束
- 对于平衡二叉树，递归和迭代版本性能相近
- 对于极不平衡的树，迭代版本更稳定

## 6. 总结

二叉树的深度问题是二叉树遍历的经典应用，通过这两个问题的学习可以掌握：

1. **递归思想**在树结构中的应用
2. **DFS与BFS**两种遍历方式的实现与对比
3. **边界条件**的处理方法
4. **时间与空间复杂度**的分析
