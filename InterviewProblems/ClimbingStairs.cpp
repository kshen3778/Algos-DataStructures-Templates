//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    
    vector<int> dp; //for memo
    int climbStairs(int n) {
        
        /*
        Pure Recursion:
        The number of ways to get to step i is = numWays(step i-1) + numWays(step i-2)
        This is good, but exceeds Time Limit
        
        Recursion + memoization:
        Doesn't run in O(n) time so TLE, but technically faster than pure recursion. Saves on Space complexity for sure.
        
        Iterative DP:
        Passes. Runs in O(n) time for sure.
        
        */
        
        for(int i=0; i<=n; i++){
            dp.push_back(-1);
        }
        
        return iterativeDP(n);
        
    }
    
    
    //Pure Recursion
    int numWays(int i){
        
        //Base cases
        if(i == 0){
            //on ground level (you don't need to move at all)
            return 1;
        }
        
        if(i == 1){
            //only one way to get to step 1
            return 1;
        }
        
        return numWays(i-1) + numWays(i-2);
        
    }
    
    //Recursion + memoization
    int numWaysMemo(int i){

        //Base cases
        if(i == 0){
            //dp[0] = 1;
            //on ground level (you don't need to move at all)
            return 1;
        }
        
        if(i == 1){
            //dp[1] = 1;
            //only one way to get to step 1
            return 1;
        }
        
        //if already exists in memory
        if(dp[i] != -1){
            return dp[i];
        }
        
        dp[i] = numWays(i-1) + numWays(i-2);
        return dp[i];
    }
    
    //Iterative DP
    int iterativeDP(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
    }
};
