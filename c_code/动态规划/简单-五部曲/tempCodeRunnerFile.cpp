    int climbStairs(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int n = 1; n <= m && i - n >= 0; n++)
            {
                dp[i] += dp[i - n];
            }
            cout << "i=" << i << " dp[i]=" << dp[i] << endl;
        }
        return dp[n];
    }