/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 * @lcpr version=30204
 *
 * [1162] 地图分析
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
    int maxDistance(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push(i * m + j);
                }
            }
        }
        if (q.empty() || q.size() == n * m)
        {
            return -1;
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int cur = q.front();
                q.pop();
                int x = cur / m;
                int y = cur % m;

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0)
                    {
                        grid[nx][ny] = 1;
                        q.push(nx * m + ny);
                    }
                }
            }
            if (!q.empty())
            {
                step++;
            }   

        }
    

        res = step;
        return res;
    }
}

;
// @lc code=end

/*
// @lcpr case=start
// [[1,0,1],[0,0,0],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,0,0],[0,0,0]]\n
// @lcpr case=end

 */
