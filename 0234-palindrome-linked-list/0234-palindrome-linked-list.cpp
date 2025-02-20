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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        string s1;
        while(temp!=NULL){
            s1+=temp->val;
            temp=temp->next;
        }
        string s2=s1;
        reverse(s2.begin(), s2.end());
        return s1==s2; 
    }
};