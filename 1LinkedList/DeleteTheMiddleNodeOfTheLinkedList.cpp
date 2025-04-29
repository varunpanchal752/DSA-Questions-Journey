// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Brute Force
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* temp = head;

        int listLen = 0;
        while(temp != NULL){
            listLen++;
            temp = temp->next;
        }

        temp = head;
        int res = listLen/2;
        while(temp != NULL){
            res--;
            if(res == 0) {
                ListNode* delNode = temp->next;
                temp->next = temp->next->next;
                delete(delNode);
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

// Optimal - Using Tortoise and Hare method
class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            if(head == NULL || head->next == NULL) return NULL;
            ListNode* slow = head;
            ListNode* fast = head;
    
            fast = fast->next->next;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode* delNode = slow->next;
            slow->next = slow->next->next;
            delete(delNode);
            return head;
        }
    };