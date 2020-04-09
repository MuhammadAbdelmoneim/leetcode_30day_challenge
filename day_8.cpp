/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
//         if(head->next == NULL)
//             return head;
//         if(head->next->next == NULL)
//             return head->next;
//         map<int , ListNode*>m;
//         ListNode *current = head;
//         int count  = 1;
//         while(current->next != NULL)
//         {
//             m.insert(std::make_pair(count , current)); 
//             current = current->next;
//            count++;
            
//         }
//             return m.at((count / 2) + 1);
        auto *A = head;
        auto *B = head;
        while(B != nullptr)
        {
            B = B->next;
            if(B == nullptr)
            {
                return A;
            }
            else
            {
                B = B->next;
                A = A->next;
            }
        }
        return A;
    }
};
