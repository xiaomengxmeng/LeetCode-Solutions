/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=30204
 *
 * [695] 岛屿的最大面积
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
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
                int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    
                    int area=dfs(grid, i, j, dirs);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
        int dfs(vector<vector<int>>& grid, int i, int j, int dirs[4][2])
    {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] =0;
        int sum = 1;
        for(int k = 0; k < 4; k++)
        {

            int x = i + dirs[k][0], y = j + dirs[k][1];
             sum+=dfs(grid, x, y, dirs);
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */

