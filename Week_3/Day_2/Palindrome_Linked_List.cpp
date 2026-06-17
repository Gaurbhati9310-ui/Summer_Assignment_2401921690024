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
// approach 2:
    ListNode *reverselist(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr =head;
        while(curr!=NULL){
            ListNode *nextnode =curr->next;
            curr->next=prev;
            prev=curr;
            curr = nextnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
     ListNode *slow=head;
     ListNode *fast = head;
     while(fast!=NULL && fast->next != NULL){
        slow=slow->next;
        fast = fast->next->next;
     }
     if(fast!=NULL){
        slow=slow->next;
     }
     slow=reverselist(slow);
     fast =head;
     while(slow!=NULL){
        if(slow->val != fast->val ){
            return false;
        }
        slow=slow->next;
        fast =fast->next;
     }
        return true;
     
    }
};

// approach1 :using stack 
//     int getlength(ListNode *head){
//         int count=0;
//         while(head!=NULL){
//             count++;
//             head=head->next;
//         }
//         return count;
//     }
//     bool isPalindrome(ListNode* head) {
//          int length=getlength(head);
//          stack<int>st;
//          ListNode *temp=head;
//          //pushing half element of ll 
//          for(int i=0;i<length/2;i++){
//             st.push(temp->val);
//             temp=temp->next;
//            }
//            // odd length
//           if(length % 2 == 1){
//            temp = temp->next;
//           }
//           while(temp!=NULL){
//            if(st.top() != temp->val){
//            return false;
//            }
//            else{
//             st.pop();
//             temp=temp->next;
//            }
//           }
//          return true;
//     }
// };
