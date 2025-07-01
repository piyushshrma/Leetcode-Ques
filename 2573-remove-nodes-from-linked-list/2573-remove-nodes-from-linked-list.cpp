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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
        vector<int> vec;

        // Step 1: Copy linked list values into vector
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        
        // Step 2: Traverse from right to left and select valid values
        vector<int> filtered;
        int maxVal = 0;

        for (int i = vec.size() - 1; i >= 0; --i) {
            if (vec[i] >= maxVal) {
                filtered.push_back(vec[i]);
                maxVal = vec[i];
            }
        }

        reverse(filtered.begin(), filtered.end());

        ListNode* heady = new ListNode(filtered[0]);
        ListNode* curr = heady;
        for(int i=1; i<filtered.size(); i++){
            curr->next = new ListNode(filtered[i]);
            curr=curr->next;
        }
        return heady;
    }
};