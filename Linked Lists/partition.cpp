/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* pivot, *curr, *prev;
    curr = pivot = A;
    prev = NULL;
    while(pivot!=NULL){
        if(pivot->val >= B)
            break;
        prev = pivot;
        pivot = pivot->next;
    }
    curr = pivot;
    pivot = prev;
    while(curr!=NULL){
        if(curr->val >= B){
            prev = curr;
            curr = curr->next;
        }
        else{
            if(pivot == NULL){
                prev->next = curr->next;
                curr->next = A;
                pivot = curr;
                A = curr;
                curr = prev->next;
                continue;
            }
            prev->next = curr->next;
            curr->next = pivot->next;
            pivot->next = curr;
            pivot = curr;
            curr = prev->next;
        }
    }
    return A;
}
