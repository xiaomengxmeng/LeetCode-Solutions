/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30204
 *
 * [210] 课程表 II
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
    vector<int> res;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        for(auto & p:prerequisites)
        {
            graph[p[1]].push_back(p[0]);
        }
        vector<int> status(numCourses, 0);
        for (int i = 0; i < numCourses;i++)
        {
            if(!status[i]&&!dfs(graph,status,i))
                return {};
        }
        reverse(res.begin(), res.end());
        return res;
        // return true;
    }
    bool dfs(const vector<vector<int>> & graph,vector<int>& status,int node)
    {
        if(status[node]==1)
            return false;
        if(status[node]==2)
            return true;
        status[node] = 1;
        for(int negighbor:graph[node])
        {
            if(!dfs(graph,status,negighbor))
                return false;
        }
        status[node] = 2;
        res.push_back(node);
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

