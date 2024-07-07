class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total_drunk = numBottles;
        int empty_bottles = numBottles;

    while(empty_bottles >= numExchange){
        int new_bottles = empty_bottles/numExchange;
        total_drunk += new_bottles;
        empty_bottles = empty_bottles % numExchange + new_bottles;
    }  

    return total_drunk;
    }
};