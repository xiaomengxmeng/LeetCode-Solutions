# 二叉搜索树（BST）全面解析

## 1. 定义与核心特性

### 1.1 基本定义
二叉搜索树（Binary Search Tree，简称 BST）是一种特殊的二叉树，满足以下**关键特性**：
- 对于树中的任意节点，其**左子树**中所有节点的值都**小于**该节点的值
- 对于树中的任意节点，其**右子树**中所有节点的值都**大于**该节点的值
- 左、右子树本身也都是二叉搜索树

### 1.2 重要特性
- **有序性**：中序遍历（左→根→右）可得到**严格递增**的节点序列
- **高效查询**：平均时间复杂度为 O(log n)，最坏情况为 O(n)（树退化为链表时）
- **动态结构**：支持高效的插入、删除和搜索操作

## 2. BST 的形成过程

BST 通过**插入操作**逐步形成，插入过程遵循 BST 的有序特性。

### 2.1 插入算法
插入新节点时，始终从根节点开始比较，根据比较结果决定向左或向右子树移动，直到找到合适的插入位置。

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);  // 找到插入位置，创建新节点
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);  // 向左子树插入
    } else {
        root->right = insertIntoBST(root->right, val); // 向右子树插入
    }
    return root;
}
```

### 2.2 形成示例
以插入序列 `[5, 3, 7, 2, 4, 6, 8]` 为例，BST 的形成过程如下：

1. 插入 5（根节点）：
   ```
       5
   ```

2. 插入 3（5 的左子节点）：
   ```
       5
      /
     3
   ```

3. 插入 7（5 的右子节点）：
   ```
       5
      / \
     3   7
   ```

4. 插入 2（3 的左子节点）：
   ```
       5
      / \
     3   7
    /
   2
   ```

5. 插入 4（3 的右子节点）：
   ```
       5
      / \
     3   7
    / \
   2   4
   ```

6. 插入 6（7 的左子节点）：
   ```
       5
      / \
     3   7
    / \  /
   2   4 6
   ```

7. 插入 8（7 的右子节点）：
   ```
       5
      / \
     3   7
    / \  / \
   2   4 6  8
   ```

最终形成一个完整的 BST，中序遍历结果为 `[2, 3, 4, 5, 6, 7, 8]`。

## 3. BST 的基本操作

### 3.1 搜索操作
从根节点开始，根据目标值与当前节点值的比较结果，向左或向右子树递归搜索。

```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return searchBST(root->left, val);  // 向左子树搜索
    } else {
        return searchBST(root->right, val); // 向右子树搜索
    }
}
```

### 3.2 删除操作
删除操作是 BST 中最复杂的操作，需要根据被删除节点的子节点情况分三种情况处理：

#### 情况 1：被删除节点是叶子节点（无左、右子节点）
直接删除该节点，返回 `nullptr`。

#### 情况 2：被删除节点只有一个子节点（左或右）
删除当前节点，将其唯一子节点提升到当前节点的位置，返回该子节点。

#### 情况 3：被删除节点有两个子节点
1. 找到右子树中的最小节点（或左子树中的最大节点）作为继任者
2. 用继任者的值替换当前节点的值
3. 递归删除继任者节点（继任者节点必定是情况 1 或情况 2）

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // 情况 1：叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // 情况 2：只有一个子节点
        else if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // 情况 3：有两个子节点
        else {
            // 找右子树的最小值节点
            TreeNode* minNode = root->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            // 替换值
            root->val = minNode->val;
            // 删除继任者节点
            root->right = deleteNode(root->right, minNode->val);
        }
    }
    return root;
}
```

## 4. 时间复杂度分析

| 操作     | 平均时间复杂度 | 最坏时间复杂度 | 最好时间复杂度 |
|----------|----------------|----------------|----------------|
| 搜索     | O(log n)       | O(n)           | O(1)           |
| 插入     | O(log n)       | O(n)           | O(1)           |
| 删除     | O(log n)       | O(n)           | O(1)           |
| 中序遍历 | O(n)           | O(n)           | O(n)           |

**最坏情况**发生在树退化为链表时（如插入有序序列 `[1, 2, 3, 4, 5]`）：
```
1
 \n  2
   \n    3
     \n      4
       \n        5
```

## 5. BST 与其他数据结构的比较

### 5.1 与数组比较
- **优势**：插入、删除操作更高效（无需移动大量元素）
- **劣势**：随机访问不如数组高效（数组支持 O(1) 随机访问）

### 5.2 与链表比较
- **优势**：搜索操作更高效（O(log n) vs O(n)）
- **劣势**：插入、删除操作相对复杂（需要维护树的结构）

### 5.3 与平衡二叉树（如 AVL 树、红黑树）比较
- **优势**：实现更简单，插入、删除操作的常数因子更小
- **劣势**：容易失衡，最坏情况下性能下降到 O(n)

## 6. 应用场景

1. **数据库索引**：许多数据库系统使用 BST 的变种（如 B+ 树）作为索引结构
2. **符号表实现**：编译器中用于存储变量名与值的映射
3. **排序算法**：树排序算法的基础
4. **优先队列**：某些优先队列实现基于 BST 变种
5. **范围查询**：高效查询某个范围内的所有元素

## 7. 代码实现示例

### 7.1 完整 BST 类实现

```cpp
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    // 递归插入辅助函数
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // 递归搜索辅助函数
    TreeNode* search(TreeNode* node, int val) {
        if (node == nullptr || node->val == val) {
            return node;
        }
        if (val < node->val) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }

    // 递归删除辅助函数
    TreeNode* remove(TreeNode* node, int key) {
        if (node == nullptr) return nullptr;
        
        if (key < node->val) {
            node->left = remove(node->left, key);
        } else if (key > node->val) {
            node->right = remove(node->right, key);
        } else {
            // 情况1和情况2
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // 情况3
            TreeNode* minNode = node->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            node->val = minNode->val;
            node->right = remove(node->right, minNode->val);
        }
        return node;
    }

    // 递归中序遍历辅助函数
    void inorderTraversal(TreeNode* node, std::vector<int>& result) {
        if (node != nullptr) {
            inorderTraversal(node->left, result);
            result.push_back(node->val);
            inorderTraversal(node->right, result);
        }
    }

    // 递归销毁树辅助函数
    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroyTree(root);
    }

    // 插入节点
    void insert(int val) {
        root = insert(root, val);
    }

    // 搜索节点
    bool search(int val) {
        return search(root, val) != nullptr;
    }

    // 删除节点
    void remove(int key) {
        root = remove(root, key);
    }

    // 中序遍历
    std::vector<int> inorderTraversal() {
        std::vector<int> result;
        inorderTraversal(root, result);
        return result;
    }

    // 层次遍历（用于打印树结构）
    void levelOrderTraversal() {
        if (root == nullptr) return;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                std::cout << node->val << " ";
                
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            std::cout << std::endl;
        }
    }
};

// 使用示例
int main() {
    BST bst;
    
    // 插入节点形成 BST
    std::vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        bst.insert(val);
    }
    
    std::cout << "层次遍历结果：" << std::endl;
    bst.levelOrderTraversal();
    
    std::cout << "中序遍历结果：" << std::endl;
    std::vector<int> inorder = bst.inorderTraversal();
    for (int val : inorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // 搜索示例
    std::cout << "搜索值 4：" << (bst.search(4) ? "找到" : "未找到") << std::endl;
    std::cout << "搜索值 9：" << (bst.search(9) ? "找到" : "未找到") << std::endl;
    
    // 删除示例
    std::cout << "删除值 5 后，层次遍历结果：" << std::endl;
    bst.remove(5);
    bst.levelOrderTraversal();
    
    return 0;
}
```

### 7.2 运行结果

```
层次遍历结果：
5 
3 7 
2 4 6 8 
中序遍历结果：
2 3 4 5 6 7 8 
搜索值 4：找到
搜索值 9：未找到
删除值 5 后，层次遍历结果：
6 
3 7 
2 4 8 
```

## 8. 总结

二叉搜索树是一种重要的数据结构，通过维护有序性实现了高效的搜索、插入和删除操作。虽然在最坏情况下性能会下降到 O(n)，但其简单的实现和良好的平均性能使其在许多应用场景中得到广泛使用。

为了克服 BST 容易失衡的问题，可以使用平衡二叉树（如 AVL 树、红黑树），它们通过旋转操作或颜色标记来保持树的平衡，确保最坏情况下的时间复杂度仍为 O(log n)。