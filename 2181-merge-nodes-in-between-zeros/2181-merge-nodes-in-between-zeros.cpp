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
typedef ListNode Node;
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        Node * ans=NULL;
        Node * temp2=NULL; 
        head = head->next;
        Node * temp = head;
        int cur_sum = 0;
        while(temp!=NULL){
            cur_sum =0;
            while(temp&&temp->val!=0){
                cur_sum+=temp->val;
                temp=temp->next;
            }
            Node * cur = new Node(cur_sum);
            if(!ans){
                ans = cur;
                temp2=cur;
            }
            else{
                temp2->next = cur;
                temp2= cur;
            }
            temp=temp->next;
        }
        return ans;
    }
};