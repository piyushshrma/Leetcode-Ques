class Solution {
public:
    const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    // Multiply two 26x26 matrices
    Matrix multiply(const Matrix& a, const Matrix& b) {
        Matrix res(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    // Fast matrix exponentiation
    Matrix matrixExpo(Matrix base, int exp) {
        Matrix result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) result[i][i] = 1;  // Identity matrix

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            exp /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Initial frequency vector
        vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Build transition matrix M
        Matrix M(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                int next_char = (i + j) % 26;
                M[next_char][i] = (M[next_char][i] + 1) % MOD;
            }
        }

        // Raise matrix M to power t
        Matrix Mt = matrixExpo(M, t);

        // Multiply Mt with initial freq vector
        vector<long long> result_freq(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                result_freq[i] = (result_freq[i] + Mt[i][j] * freq[j]) % MOD;
            }
        }

        // Sum of all frequencies = final length
        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + result_freq[i]) % MOD;
        }
        return total;
    }
};



// class Solution {
// public:

//     const int MOD = 1e9+7;
//     int lengthAfterTransformations(string s, int t, vector<int>& nums) {
//         while(t--){
//            string new_s="";

//            for(char c : s){
//             int count=nums[c-'a'];
//             for(int j=1; j<=count; j++){
//                 char next_char = (c - 'a' + j) % 26 + 'a';
//                 new_s.push_back(next_char);
//             }
//            }
//            s=new_s;
//         }
//         return s.length();
//     }
// };