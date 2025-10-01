class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;
        int empties = numBottles;

        while (empties >= numExchange) {
            int newBottles = empties / numExchange;
            totalDrank += newBottles;
            empties = empties % numExchange + newBottles;
        }

        return totalDrank;
    }
};