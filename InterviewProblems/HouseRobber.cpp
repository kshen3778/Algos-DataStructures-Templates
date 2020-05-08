//https://leetcode.com/problems/house-robber/submissions/
class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        //https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
        //What it boils down to, which loot is bigger:
        //1. Loot from current house[i] + all loot from house[i - 2] and backwards
        //or
        //2. Loot from previous house[i-1] and backwards
        
        //initialize array for memo solution
        for(int i=0; i<nums.size(); i++){
            memo.push_back(-1); //-1 means unfilled
        }
        
        return getLoot_iter(nums);
        
    }
    
    /*
    RECURSIVE SOLUTION: TIME LIMIT EXCEEDED
    
    int getLoot(vector<int>& loot, int i){
        
        //at the beginning we have zero loot
        if(i < 0){
            return 0;
        }
        
        //if we decide to rob house[i], we get its loot (loot[i]) and all of the loot we had previously (getLoot(loot, i-2))
        int rob_loot = loot[i] + getLoot(loot, i - 2);
        
        //if we decide to spare house[i], we have all of the loot we had previously (getLoot(loot, i-1))
        int spare_loot = getLoot(loot, i - 1);
        
        //take the option that results in the bigger loot
        return max(rob_loot, spare_loot);
    }*/
    
    //Use memoization + recursion
    int getLoot(vector<int>& loot, int i){
        
        //at the beginning we have zero loot
        if(i < 0){
            return 0;
        }
        
        if(memo[i] != -1){
            return memo[i];
        }
        
        //if we decide to rob house[i], we get its loot (loot[i]) and all of the loot we had previously (getLoot(loot, i-2))
        int rob_loot = loot[i] + getLoot(loot, i - 2);
        
        //if we decide to spare house[i], we have all of the loot we had previously (getLoot(loot, i-1))
        int spare_loot = getLoot(loot, i - 1);
        
        //take the option that results in the bigger loot
        memo[i] = max(rob_loot, spare_loot); //store result
        return memo[i];
    }
    
    //Use memoization + iterative (pretty much same as recursion except saving on the return call stack memory) still O(n) memory
    //honestly this is the same as memo + recursion above
    //for the most optimal but not intuitive see Step 5 in the link above
    int getLoot_iter(vector<int>& loot){
        
        if(loot.size() == 0){
            return 0;
        }
        
        memo[0] = loot[0];
        for(int i=1; i<loot.size(); i++){
            //this is just to avoid array out of bounds errors
            int memo2;
            int memo1;
            if((i-2) < 0){
                memo2 = 0;
            } else{
                memo2 = memo[i-2];
            }
            
            if((i-1) < 0){
                memo1 = 0;
            } else{
                memo1 = memo[i-1];
            }

            memo[i] = max(loot[i] + memo2, memo1);
        }
        
        return memo[loot.size() - 1];
        
    }
    
};
