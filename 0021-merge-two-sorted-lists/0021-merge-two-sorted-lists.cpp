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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> nums;
        ListNode* temp1=list1;
        ListNode* temp2=list2;

        if (list1 == NULL && list2 == NULL) return NULL;

        while(temp1!=NULL){
            nums.push_back(temp1->val);
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            nums.push_back(temp2->val);
            temp2=temp2->next;
        }

        sort(nums.begin(), nums.end());

        ListNode* head = new ListNode(nums[0]);
        ListNode* current = head;

        for (int i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
        }
        return head;
    }
};