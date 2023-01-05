// https://leetcode.com/problems/rotate-function/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0, f = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            f += i * nums[i];
        }
        int ans = f;
        for (int i = n - 1; i > 0; i--)
        {
            f = f + sum - n * nums[i];
            ans = max(ans, f);
        }
        return ans;
    }
};