// https://leetcode.com/problems/largest-divisible-subset/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxIndex])
                maxIndex = i;
        }
        vector<int> ans;
        while (maxIndex != -1)
        {
            ans.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }
        return ans;
    }
};