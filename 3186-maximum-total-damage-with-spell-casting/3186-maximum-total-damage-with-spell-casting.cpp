class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> mp;

        vector<long long> uni;

        for (auto &x : power) {
            mp[x]++;
            if (mp[x] == 1) uni.push_back(x);
        }

        sort(uni.begin(), uni.end());

        long long n = uni.size(), ans = 0;

        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {
            long long elem = uni[i];
            long long curr = elem * mp[elem];
            dp[i] = curr;
            for (int j = i - 1; j >= i - 3 && j >=0; j--) {
                if (uni[j] < elem - 2)
                dp[i] = max(dp[i], dp[j] + curr);
            }

            ans = max(ans, dp[i]);

            if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
        }

        return ans;


    }
};