//https://leetcode.com/problems/swap-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//Traverse the list in pairs, keeping track of each section: prev->node1->node2->next
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        //list is empty
        if(head == NULL){
            return NULL;
        }
        
        //list only has 1 element
        if(head->next == NULL){
            return head;
        }
        
        ListNode* prevnode = NULL; //the node before a pair
        ListNode* node1 = head; //second node in a pair
        ListNode* node2 = head->next; //first node in a pair
        ListNode* nextnode = node2->next; //the node after a pair
        
        ListNode* newHead = node2; //the new head of the returned list is the second node in the first pair;
        
        while(true){
            
            //swap
            node2->next = node1;
            node1->next = nextnode;
            if(prevnode != NULL){ //at beginning prevnode is null
                prevnode->next = node2;
            }
            
            //increment to next pair
            prevnode = node1;
            node1 = prevnode->next;
            //if either node1 or node2 is null that means the list either has 2 elements or has an odd number of elements
            if(node1 == NULL){
                //list has only 2 elements
                break;
            }
            node2 = node1->next;
            if(node2 == NULL){
                //list has odd number of elements
                break;
            }
            nextnode = node2->next;
        }
        
        return newHead;
    }
};
