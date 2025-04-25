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

// class Solution {
// public:

//     int digitSum(int num){
//         int sum=0;
//         while(num){
//             int rem=num%10;
//             sum+=rem;
//             num=num/10;
//         }
//         return sum;
//     }

//     int countLargestGroup(int n) {
//         if(n<=9){
//             return n;
//         }
//         map<int, int> mp;
//         for(int i=1; i<=n; i++){
//             if(i<=9){
//             mp[i]++;}

//             else{
//                 int thatSum = digitSum(i);
//                 mp[thatSum]++;
//             }
//         }
//         int maxAns=INT_MIN;
//         for(auto& i : mp){
//             maxAns=max(maxAns, i.second);
//         }

//         int ans=0;
//         for(auto& i : mp){
//             if(i.second==maxAns){
//                 ans++;
//             }
//         }

//         return ans;
//     }
// };
