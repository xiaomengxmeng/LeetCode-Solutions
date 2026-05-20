/*
 * @lc app=leetcode.cn id=417 lang=cpp
 * @lcpr version=30204
 *
 * [417] 太平洋大西洋水流问题
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
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> res, PacVisited, AltVisited;
        int m = heights.size(), n = heights[0].size();
        PacVisited.resize(m, vector<int>(n, 0));
        AltVisited.resize(m, vector<int>(n, 0));
        // 太平洋：上边界 + 左边界
        for (int i = 0; i < m; i++)
            dfs(heights, PacVisited, i, 0);
        for (int j = 0; j < n; j++)
            dfs(heights, PacVisited, 0, j);

        // 大西洋：下边界 + 右边界
        for (int i = 0; i < m; i++)
            dfs(heights, AltVisited, i, n - 1);
        for (int j = 0; j < n; j++)
            dfs(heights, AltVisited, m - 1, j);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (PacVisited[i][j] && AltVisited[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &Visited, int i, int j)
    {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size())
            return;
        if (Visited[i][j])
        {
            return;
        }
        Visited[i][j] = 1;
        if (i + 1 < heights.size() && heights[i + 1][j] >= heights[i][j])
        {
            dfs(heights, Visited, i + 1, j);
        }
        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j])
        {
            dfs(heights, Visited, i - 1, j);
        }
        if (j + 1 < heights[0].size() && heights[i][j + 1] >= heights[i][j])
        {
            dfs(heights, Visited, i, j + 1);
        }
        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j])
        {
            dfs(heights, Visited, i, j - 1);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1],[1,2]]\n
// @lcpr case=end

 */
