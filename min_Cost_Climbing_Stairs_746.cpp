//QUESTION: https://leetcode.com/problems/min-cost-climbing-stairs/
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

//SOLUTION
class Solution {
public:
    vector<int> lookup;
    int sum(vector<int>& cost, int i, int n){
//         if like below, then when i>n, it first checks lookup[i] which is out of bounds => heap overflow
//         if(lookup[i] != -1) return lookup[i];
//         if(i>=n) return 0; //reaches top
           
//         if(lookup[n] == -1) then empty
        
        if(i>=n) return 0; //reaches top
        if(lookup[i] != -1) return lookup[i];
           
        int optionA = cost[i] + sum(cost,i+1,n);
        int optionB = cost[i] + sum(cost,i+2,n);
        return lookup[i] = min(optionA, optionB);
        
        //RECURSIVE SOLUTION PART
        // int optionA = cost[i] + sum(cost,i+1,n);
        // int optionB = cost[i] + sum(cost,i+2,n);
        // return min(optionA, optionB); // calculating the smallest part through each subtree and comparing it above, till it reaches top
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        lookup = vector<int>(n,-1);
        return min(sum(cost,0,n), sum(cost,1,n));
    }
};
