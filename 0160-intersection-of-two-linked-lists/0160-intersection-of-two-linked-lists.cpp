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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mp;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
            mp[temp1]++;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            mp[temp2]++;
            temp2=temp2->next;
        }

        for(auto& i : mp){
            if(i.second >=2 ){
                return i.first;
            }
        }

        return NULL;
    }
};