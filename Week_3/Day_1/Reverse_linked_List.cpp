/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // approach 2: iterative way 
        // time complexity : O(1);
        // space complexity : O(n);
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr!=NULL){
        ListNode *nextnode = curr->next;
        curr->next = prev;
        prev=curr;
        curr=nextnode;
        }
        return prev;
    }
};

        // approach 1 : recursive way
        // timecomplexity = O(n);
        // spacecomplexity = O(n);
//         if(head ==NULL || head->next == NULL){
//             return head;
//         }
//         ListNode* last = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return last;
//     }
// };
