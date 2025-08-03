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
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(!h1) return h2;
        if(!h2) return h1;

        if(h1->val <= h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        }
        else{
            h2->next=merge(h1, h2->next);
            return h2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
};


// using extra space of vector
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         vector<int> nums;
//         ListNode* temp1=list1;
//         ListNode* temp2=list2;

//         if (list1 == NULL && list2 == NULL) return NULL;

//         while(temp1!=NULL){
//             nums.push_back(temp1->val);
//             temp1=temp1->next;
//         }

//         while(temp2!=NULL){
//             nums.push_back(temp2->val);
//             temp2=temp2->next;
//         }

//         sort(nums.begin(), nums.end());

//         ListNode* head = new ListNode(nums[0]);
//         ListNode* current = head;

//         for (int i = 1; i < nums.size(); ++i) {
//         current->next = new ListNode(nums[i]);
//         current = current->next;
//         }
//         return head;
//     }
// };