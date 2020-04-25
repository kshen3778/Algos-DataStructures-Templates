//https://leetcode.com/problems/super-egg-drop/
class Solution {
public:
            //a state is (K,N) - K eggs to use, and N floors remaining, has the value of the most amount of drops needed
        //in addition to state, there is also X which is the current  floor you're dropping the egg
        //(K,N) = 1 + max((K-1, X-1) + (K, N - X)) 
        //(K-1, X-1) is if at X when you drop it it breaks, you have K-1 eggs left, and need to search all floors below X
        //(K, N-X) is if at X when you drop it it remains intact, you still have K eggs left, and # of floors above X to check
        // +1 is for the drop you made at the Xth floor
        //select the option with the greater amount of tries
        //Then you need to find the best floor X (which is the state with the least value), this can be found via binary search

        //we will implement the iterative solution + binary search to optimize it
    /*
    Alternate way to write it:
    //Recursive Solution (can also replace for loop with binary search)
    // the current state is K eggs, with N floors
    // return the best solution in this state 
    
    memo = dict()
    def dp(K, N) -> int:
        #base case
        if K == 1: return N;
        if N == 0: return 0;
        //avoid  duplicates
        if (K, N) in memo:
            return memo[(K,N)]
        
        res = float('INF')
        //all the possible choice
        for i in range(1, N+1):
            res = min(res, max(dp(K, N - i), dp(K - 1, i - 1)) + 1)
        memo[(K,N)] = res
        return res
    //then in the main function just do return dp(K,N)
    */
    
    //Iterative Solution (DP + binary search)
    int superEggDrop(int K, int N) {

        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        
        //base cases
        for(int i=0; i<K+1; i++){
            dp[i][1] = 1; //i eggs, 1 floor
        }
        
        for(int j=0; j<N+1; j++){
            dp[1][j] = j; //1 egg, j floors
        }
        //note: the 0th row/col is invalid/not counted

        //populate dp matrix (start at rows,cols = 2 since rest are filled by base cases)
        for(int i=2; i<K+1; i++){
            for(int j=2; j<N+1; j++){
                //conduct binary search to find optimal X values for state (i,j)
                int min_val = INT_MAX;
                int low = 1;
                int high = j;

                while(low <= high){
                    int mid = (low + high) / 2;
                    int left = dp[i-1][mid-1]; //broke when dropped (T1 line)
                    int right = dp[i][j-mid]; //intact when dropped (T2 line)
                    
                    //update the current min value found
                    min_val = min(min_val, max(dp[i - 1][mid - 1], dp[i][j - mid]) + 1);

                    if(left == right){
                        break;
                    }
                    else if (left < right){
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                //optimal minimum value found at X=low, now set for state (i,j)
                dp[i][j] = min_val;

            }
        }
        
        return dp[K][N];
    }
};
