// QUESTION
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// SOLUTION - 1
class Solution {
public:
    int solve(int i, int size, vector<int>& nums, vector<int>& lookup){
        if(i > size) return 0;
        if(lookup[i]!= -1) return lookup[i];
        
        int ans = max(nums[i] + solve(i+2, size, nums, lookup), nums[i] + solve(i+3, size, nums, lookup));
        lookup[i] = ans;
        return ans; //if return lookup[i], time increases, since search through lookup everytime
        
    }
    
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> lookup(size+1, -1);
        
        return max(solve(0,size-1,nums,lookup), solve(1,size-1,nums,lookup));
        
    }
};

// SOLUTION - 1
class Solution {
public:
    int solve(int i, int size, vector<int>& nums, vector<int>& lookup){
        if(i > size) return 0;
        if(lookup[i]!= -1) return lookup[i];
        
      //if robbed i, then take rob i+2 and present; if not robbed i, then rob i+1 only
        int ans = max(nums[i] + solve(i+2, size, nums, lookup), solve(i+1, size, nums, lookup));
        lookup[i] = ans;
        return ans;
        
    }
    
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> lookup(size+1, -1);
        
        return solve(0,size-1,nums,lookup);
        
    }
};
