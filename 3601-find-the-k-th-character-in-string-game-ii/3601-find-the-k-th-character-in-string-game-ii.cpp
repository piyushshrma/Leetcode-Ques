class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int shift = 0;
        vector<long long> lengths;
        long long len = 1;

        for (int op : operations) {
            len *= 2;
            lengths.push_back(len);
            if (len >= k) break;
        }

        for (int i = lengths.size() - 1; i >= 0; --i) {
            long long half = lengths[i] / 2;
            int op = operations[i];
            if (k > half) {
                k -= half;
                if (op == 1) shift++;
            }
        }

        return (char)((('a' - 'a' + shift) % 26) + 'a');
    }
};

// class Solution {
// public:
//     string helper0(string s, long long k){
//         s=s+s;
//         return s;
//     }
//     string helper1(string s, long long k){
//     string news = s;
//     while(news.length() < k){
//         string add = "";
//         for(char c : news){
//             if(c == 'z') add += 'a';
//             else add += c + 1;
//         }
//         news += add;
//     }
//     return news;
// }

//     char kthCharacter(long long k, vector<int>& operations) {
//         string ini="a";
//         string ans;
//         for(int i=0; i<operations.size(); i++){
//             if(operations[i]==0){
//                 // operations[i]=0
//                 ans=helper0(ini, k);
//                 ini=ans;
//             }

//             else{
//                 // operations[i]=1
//                 ans=helper1(ini, k);
//                 ini=ans;
//             }
//         }
//         return ans[k-1];
//     }
// };