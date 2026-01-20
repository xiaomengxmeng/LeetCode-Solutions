/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=30204
 *
 * [6] Z 字形变换
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
    /*
       n= s.length()
       numRows * numRow -1 中有 numRows+numRows-2 个字符
       最大需要的二维数组空间 numRows * n/numRows+numRows-2
    */
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows==1) return s;
        int numCols = n/(numRows+numRows-2)*(numRows-1)+n%(numRows+numRows-2);
        vector<vector<char>> res(numRows,vector<char>(numCols,' '));
        int i=0,j=0;
        for(int k=0;k<n;k++)
        {
            res[i][j]=s[k];
            if(k%(numRows+numRows-2)<numRows-1)
            {
                i++;
            }
            else
            {
                i--;
                j++;
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<numCols;j++)
            {
                if(res[i][j]!=' ')
                {
                    ans+=res[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */

