/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30204
 *
 * [79] 单词搜索
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
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}}; //four directions
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                if(dfs(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board ,string &word ,int k, int i,int j){
        int m = board.size();
        int n = board[0].size();
        if(i<0||i>=m||j<0||j>=n)
            return false;
        if(board[i][j]!=word[k])
            return false;
        if(k==word.size()-1)
            return true;
        char temp = board[i][j];
        board[i][j] = '#';
        for (int d = 0; d < 4;d++){
            if(dfs(board, word, k + 1, i + dirs[d][0], j + dirs[d][1]))
                return true;
        }
        board[i][j] = temp;
        return false;
        }
};
// @lc code=end



/*
// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCB"\n
// @lcpr case=end

 */

