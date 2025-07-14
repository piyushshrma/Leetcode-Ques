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
    int getDecimalValue(ListNode* head) {
        string s="";
        ListNode* temp=head;
        while(temp!=NULL){
            s+=to_string(temp->val);
            temp=temp->next;
        }
        int power=0;
        int ans=0;
        for(int i=s.size()-1; i>=0; i--){
            ans += (s[i] - '0') * pow(2, power);
            power++;
        }
        return ans;
    }
};