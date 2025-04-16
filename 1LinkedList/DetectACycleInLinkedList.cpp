// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Using hashing
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp!=NULL){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp]= 1;
            temp=temp->next;
        }
        return false;
    }
};

// Using tortoise and Hare method
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
    
                if(slow == fast){
                    return true;
                }
            }
            return false;
        }
    };