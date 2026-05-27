/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30204
 *
 * [875] 爱吃香蕉的珂珂
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
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1,right = *max_element(piles.begin(),piles.end());
        while(left<right){
            int mid = left + (right-left)/2;
            if(canEat(piles,mid,h)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
    bool canEat(vector<int> & piles,int K,int h)
    {
        int count = 0;
        for(auto p:piles){
            count+=(p+K-1)/K;
        }
        return count<=h;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */

