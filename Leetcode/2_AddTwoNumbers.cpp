class Solution {
public:
    void add(ListNode* &l1, ListNode* &l2, int carry)
    {
        int v = 0;
        if(l1 == NULL && l2 == NULL)
        {
            if(carry == 1) l1 = new ListNode(1);
            return;
        } 
        else if(l1 == NULL)
        {
            v = l2->val + carry;
            l1 = new ListNode();
        }
        else if(l2 == NULL) v = l1->val + carry;
        else v = l1->val + l2->val + carry;
        l1->val = v%10;
        carry = v/10;
        ListNode* l2_next = l2 == NULL ? NULL: l2->next;
        add(l1->next, l2_next, carry);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        add(l1, l2, 0);
        return head;
    }
};