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
// 2-pass solution 
    int getlength(ListNode *head){
        int length =0;
        while(head!=NULL){
        length++;
        head=head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getlength(head);
        int travel_front = length - n;
        if(length==n){
            ListNode *curr = head->next;
            delete(head);
            return curr;
        }
        ListNode *prev =NULL;
        ListNode *temp =head;
        while(travel_front--){
            prev=temp;
            temp= temp->next;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
    }
};
