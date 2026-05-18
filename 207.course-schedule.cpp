/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
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
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        // 邻接表构建图
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
        }
        vector<int> status(numCourses, 0);
        // DFS检测环
        for (int i = 0; i < numCourses; i++)
        {
            if (!status[i] && !dfs(graph, status, i))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(const vector<vector<int>> &graph, vector<int> &status, int node)
    {
        if (status[node] == 1)
            return false; // 环
        if (status[node] == 2)
            return true; // 已安全
        status[node] = 1;
        for (int neighbor : graph[node])
        {
            if (!dfs(graph, status, neighbor))
                return false;
        }
        status[node] = 2; // ✅ 标记为已安全完成
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */
