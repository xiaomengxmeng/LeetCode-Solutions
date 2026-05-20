/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30204
 *
 * [994] 腐烂的橘子
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
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (i + 1 < m && grid[i + 1][j] == 1)
                {
                    q.push({i + 1, j});
                    grid[i + 1][j] = 2;
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    q.push({i - 1, j});
                    grid[i - 1][j] = 2;
                }
                if (j + 1 < n && grid[i][j + 1] == 1)
                {
                    q.push({i, j + 1});
                    grid[i][j + 1] = 2;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    q.push({i, j - 1});
                    grid[i][j - 1] = 2;
                }
            }
            if (!q.empty())
                count++;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */
