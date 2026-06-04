/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30204
 *
 * [200] Number of Islands
 *
 * [Review] Original completion: 2026-05-18
 * Key technique: Grid DFS (flood fill) - mark visited by sinking land
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
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};



public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0)
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++)
        {
            dfs(grid, i + dirs[k][0], j + dirs[k][1]);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end
 */