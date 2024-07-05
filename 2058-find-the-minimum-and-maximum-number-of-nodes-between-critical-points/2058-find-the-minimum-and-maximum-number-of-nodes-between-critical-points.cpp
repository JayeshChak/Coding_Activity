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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minima = INT_MAX, maxima = 0;
        int prev = head->val, next = 0;
        int prevCritical = 0, i = 1;
        head = head->next;

        while(head->next!=nullptr){
            next = head->next->val;

            if(head->val > prev && head->val > next || head->val < prev && head->val < next){
                if(prevCritical) {
                    maxima+=i-prevCritical;
                    minima=min(minima, i-prevCritical);
                }
                prevCritical = i;
            }

            prev = head->val;
            head = head->next;
            ++i;
        }

        return maxima ? vector<int>{minima, maxima} : vector<int>{-1, -1};
    }
};