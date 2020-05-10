//https://leetcode.com/problems/search-insert-position/submissions/
class Solution {
public:
    //binary search + manual work
    int searchInsert(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        int mid = (min + max) / 2;
        
        while(min < max){
            int mid = (min + max) / 2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] < target){
                min = mid + 1;
                if(min >= nums.size()){
                    min = nums.size() - 1;
                }
            } else {
                max = mid - 1;
                if(max < 0){
                    max = 0;
                }
            }
        }

        //not found: two possible cases
        
        //Case 1: min == max
        if(min == max){
            if(target == nums[min]){
                //in the case of a one element array this is a special case that's not caught by the binary search
                return min;
            }
            else if(target < nums[min]){
                return min;
            } else{
                return min + 1; //the next index
            }
        }
        // Case 2: min > max
        else{
            //target is either supposed to be < max, between max <---> min, or > min
            if(target < nums[max]){
                return max;
            }
            else if(target > nums[max] && target < nums[min]){
                return min;    
            } 
            else{
                return min + 1;
            }
        }
        
        
    }
};
