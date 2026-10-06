#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(vector<int> &arr, int idx, vector<int> &dp)
    {
        if (idx == 0)
            return arr[0];
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int pick = arr[idx] + f(arr, idx - 2, dp);
        int skip = f(arr, idx - 1, dp);

        return dp[idx] = max(pick, skip);
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> arr(maxi + 1, 0);
        for (int i = 0; i < n; i++)
        {
            arr[nums[i]] += nums[i];
        }
        vector<int> dp(maxi+1, -1);
        return f(arr,maxi,dp);
    }
};