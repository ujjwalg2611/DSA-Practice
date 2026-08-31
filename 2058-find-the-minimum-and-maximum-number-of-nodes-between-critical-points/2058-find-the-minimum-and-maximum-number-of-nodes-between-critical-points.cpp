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
        int mini = INT_MAX, maxi = INT_MIN;
        ListNode* prev = head;
        ListNode* temp = head->next;
        int ind = 1;
        vector<int> pos;
        while(temp && temp->next){
            ListNode* front = temp->next;
            if(prev->val < temp->val && temp->val > front->val) pos.push_back(ind);
            if(prev->val > temp->val && temp->val < front->val) pos.push_back(ind);

            ind++;
            prev = temp;
            temp = front;
        }
        int m = pos.size();
        if(m <= 1) return {-1, -1};

        maxi = pos[m-1] - pos[0];

        for(int i=1;i<m;i++){
            mini = min(pos[i] - pos[i-1], mini);
        }
        
        return {mini, maxi};
    }
};