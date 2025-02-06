class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;  // Map to store the count of each product

        // Calculate the product of each unique pair of numbers
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int product = nums[i] * nums[j];
                ++productCount[product];  // Increment the count of this product
            }
        }

        int answer = 0;
        // Iterate through the map to calculate the number of tuples from the count of each product
        for (auto& [product, count] : productCount) {
            // Each product that has been found more than once can form 
            // a certain number of tuples. This is a combinatorial problem: 
            // if a product is the result of `count` pairs, then the number 
            // of tuples is the number of ways to pick 2 pairs out of `count`,
            // which is `count` choose 2.
            answer += count * (count - 1) / 2;
        }

        // Each tuple can be permuted in 8 different ways since the tuple (a, b, c, d)
        // can give us 2 distinct equations by swapping the pairs: a*b = c*d AND a*c = b*d,
        // and each equation has 4 permutations (a * b, b * a, c * d, d * c).
        return answer * 8;
    }
};
