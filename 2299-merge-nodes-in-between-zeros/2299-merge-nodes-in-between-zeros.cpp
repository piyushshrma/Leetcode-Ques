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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* heady = new ListNode(0);
        ListNode* curr = heady;

        int sum=0;

        while(temp!=NULL){
            if(temp->val != 0){
                sum+=temp->val;
            }
            else{
                if(sum!=0){
                    curr->next = new ListNode(sum);
                    curr=curr->next;
                    sum=0;
                }
            }
            temp=temp->next;
        }
        heady=heady->next;
        return heady;
    }
};

// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         vector<int> ll;
//         ListNode* temp = head;

//         //vector me saari val daal di
//         while(temp!=NULL){
//             ll.push_back(temp->val);
//             temp=temp->next;
//         }
        
//         vector<int> nayavec;
//         int sum=0;
//         for(int i=0; i<ll.size(); i++){
//             if(ll[i]!=0){
//                 sum+=ll[i];
//             }
//             else{
//                 if(sum!=0){
//                 nayavec.push_back(sum);
//                 sum=0;
//                 }
//             }
//         }

//         ListNode* heady = new ListNode(nayavec[0]);
//         ListNode* tempy = heady;
//         for(int i=1; i<nayavec.size(); i++){
//             tempy->next=new ListNode(nayavec[i]);
//             tempy=tempy->next;
//         }
//         return heady;
//     }
// };