class Solution {
public:
// approach2 :
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // base case 
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    ListNode* result ;
    if(list1->val <= list2->val){
        result= list1;
        result->next=mergeTwoLists(list1->next,list2);
    }
    else{
        result=list2;
       result->next= mergeTwoLists(list1,list2->next);
    }
    return result;
  }

};

// approach1 : 
//     ListNode* merge(ListNode* left, ListNode* right) {
//         ListNode dummy(-1);
//         ListNode* temp = &dummy;

//         while (left && right) {
//             if (left->val <= right->val) {
//                 temp->next = left;
//                 left = left->next;
//             } else {
//                 temp->next = right;
//                 right = right->next;
//             }
//             temp = temp->next;
//         }

//         temp->next = (left ? left : right);
//         return dummy.next;
//     }

//     ListNode* findMid(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head->next;

//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         return slow;
//     }

//     ListNode* sortList(ListNode* head) {
//         if (!head || !head->next)
//             return head;

//         ListNode* mid = findMid(head);

//         ListNode* right = mid->next;
//         mid->next = NULL;

//         ListNode* left = sortList(head);
//         right = sortList(right);

//         return merge(left, right);
//     }

//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

//         if (list1 == NULL) return list2;
//         if (list2 == NULL) return list1;

//         ListNode* temp = list1;

//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = list2;
//         return sortList(list1);
//     }
// };
