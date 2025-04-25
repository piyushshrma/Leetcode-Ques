class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
            mp[digitSum(i)]++;

        int maxFreq = 0, ans = 0;
        for (auto& it : mp)
            maxFreq = max(maxFreq, it.second);

        for (auto& it : mp)
            if (it.second == maxFreq)
                ans++;

        return ans;
    }
};
