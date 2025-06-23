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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        vector<int> arr;
        
        // Step 1: Copy all values from the linked list
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        // Step 2: Filter out the unwanted value
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=val){
                ans.push_back(arr[i]);
            }
        }

        // Step 3: Handle empty result (all elements were removed)
        if (ans.empty()) {
            return NULL;
        }

        // Step 4: Rebuild linked list from filtered values
        ListNode* heady = new ListNode(ans[0]);
        ListNode* curr=heady;
        for(int i=1; i<ans.size(); i++){
            curr->next=new ListNode(ans[i]);
            curr=curr->next;
        }

        return heady;
    }
};