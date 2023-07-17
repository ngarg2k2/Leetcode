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
    ListNode* reverse(ListNode* head){
        if (head==NULL||head->next==NULL){
            return head;
        }
        ListNode* ans = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=reverse(l1);
        ListNode* head2=reverse(l2);
        ListNode* ans=new ListNode(-1);
        ListNode* tmp=ans;
        int carry=0;
        while(head1||head2||carry){
            int sum=0;
            sum=sum+carry;
            if(head1){
                sum=sum+head1->val;
                head1=head1->next;
            }
            if(head2){
                sum=sum+head2->val;
                head2=head2->next;
            }
            carry=sum/10;
            sum=sum%10;
            ListNode* n=new ListNode(sum);
            ans->next=n;
            ans=ans->next;
        }
        ans=reverse(tmp->next);
        return ans;
    }
};