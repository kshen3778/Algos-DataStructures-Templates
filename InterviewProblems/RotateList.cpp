//https://leetcode.com/problems/rotate-list/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//get length of the list, at the same time, when you get to the tail, reconnect it to the head
//then get the split index by doing n = len - (k % len)
//traverse to the nth node (starting at n=1) and then take its pointer and rewire it to null (thus making it the last node)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        //edge cases
        if(head == NULL){
            return NULL;
        }
        
        if(head->next == NULL){
            return head;
        }
            
        //------------
        
        int len = 1;
        
        ListNode* cur = head;
        while(cur->next != NULL){
            cur = cur->next;
            len++;
        }
        //cur is now the tail at this point
        //reconnect  it to head
        cur->next = head;
        
        //go to the node at split index
        int split = len - (k % len);
        ListNode* node = head;
        for(int n=1; n<split; n++){
            node = node->next;
        }
        //rewire it to NULL and return the new head
        ListNode* newhead = node->next;
        node->next = NULL;
        
        return newhead;
        
    }
};
