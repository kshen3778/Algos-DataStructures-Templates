//https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> newList;
        //todo: what if at an index there are multiple start and ends like ((( or ()(), need to hold in an array
        
        //Use an ordered map to store vector of bounds (0 = start bound "(", 1 = end bound ")" )
        //then you loop through the ordered map: if it's a start bound pop it into the stack and if it's the first one in and there are no more then set startIndex
        //keep looping: start bounds = pop in, end bounds = pop out
        //if a pop out results in an empty stack at the end then set endIndex
        
        //when there are multiple bounds at a number, computer all the pop in and pop out operations, then check if empty
        
        map<int, vector<int>> bound_map;
        
        //populate and insert into map
        for(int i=0; i<intervals.size(); i++){
            
            //loop through each element in pair (always a constant size 2)
            for(int j=0; j<intervals[i].size(); j++){

                if(j == 0){
                    bound_map[intervals[i][j]].push_back(0); //add a start bound
                } else {
                    bound_map[intervals[i][j]].push_back(1); //set as a end bound
                }
                
            }
        }
        
        
        //loop through map
        stack<int> bound_stack;
        
        int start = -1;
        int end = -1;
        
        for (const auto &p : bound_map){
            
           //cout << p.first << ": ";
           // for(int i=0; i<p.second.size(); i++){
           //     cout << p.second[i] << " ";
           // }
           //cout << endl;
          
           if(bound_stack.empty()){
               //if the stack is empty, then set start
               start = p.first;
           }
           for(int i=0; i<p.second.size(); i++){
               if(p.second[i] == 0){
                   bound_stack.push(p.first);
               }
               
               if(p.second[i] == 1){
                   bound_stack.pop();
               }
           }
            if(bound_stack.empty()){
                //cout << "empty" << endl;
                end = p.first;
                //if at the end stack is empty, record the new interval
                vector<int> newInterval = {start, end};
                newList.push_back(newInterval);
                
                
                //reset start and end markers (might not be necessary)
                start = -1;
                end = -1;
            }
           
        }
        
        
        return newList;
    }
};
