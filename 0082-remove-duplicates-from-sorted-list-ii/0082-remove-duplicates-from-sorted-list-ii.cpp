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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* temp=head;

        vector<int> arr;
        
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        map<int,int> mp;

        for(auto& i : arr){
            mp[i]++;
        }

        vector<int> finVec;

        for(auto& i : mp){
            if(i.second==1){
                finVec.push_back(i.first);
            }
        }
        if(finVec.size()==0) return NULL;

        ListNode* heady = new ListNode(finVec[0]);
        ListNode* curr = heady;
        if(finVec.size()==1) return heady;
        for(int i=1; i<finVec.size(); i++){
            curr->next=new ListNode(finVec[i]);
            curr=curr->next;
        }

        return heady;
    }
};