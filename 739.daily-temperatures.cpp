/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30204
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st;
        for (int i = 0; i < temperatures.size();i++)
        {
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                    int top=st.top();
                    st.pop();
                    res[top]=i-top;
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

