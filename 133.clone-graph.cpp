/*
 * @lc app=leetcode.cn id=133 lang=cpp
 * @lcpr version=30204
 *
 * [133] 克隆图
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Node* cloneGraph(Node* node) {
    //     if (!node) return nullptr;
    //     unordered_map<Node*, Node*> visited;
    //     return dfs(node, visited);
    // }
    // Node * dfs(Node *node,unordered_map<Node*,Node*>& visited){
    //     if(visited.find(node)!=visited.end()){
    //         return visited[node];
    //     }
    //     Node *clone = new Node(node->val);
    //     visited[node]=clone;   
    //     for(auto neighbor:node->neighbors){
    //         clone->neighbors.push_back(dfs(neighbor,visited));
    //     }
    //     return clone;
    // }
    Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> visited;
    visited[node] = new Node(node->val);
    queue<Node*> q{{node}};
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        for (auto& n : cur->neighbors) {
            if (!visited.count(n)) {
                visited[n] = new Node(n->val);
                q.push(n);
            }
            visited[cur]->neighbors.push_back(visited[n]);
        }
    }
    return visited[node];
}
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4],[1,3],[2,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

