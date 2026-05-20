/*
 * @lc app=leetcode.cn id=130 lang=cpp
 * @lcpr version=30204
 *
 * [130] 被围绕的区域
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
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = 'T';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
        return;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]\n
// @lcpr case=end

// @lcpr case=start
// [['X']]\n
// @lcpr case=end

 */
