// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Using Stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        stack<int> stck;
        ListNode* temp = head;

        while(temp != NULL){
            stck.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            if(temp->val != stck.top()){
                return false;
            }
            stck.pop();
            temp = temp->next;
        }
        return true;
    }
};

// Using Tortoise And Hare Method
class Solution {
    public:
        ListNode* reverseList(ListNode* head){
            if(head == NULL || head->next == NULL) return head;
    
            ListNode* newHead = reverseList(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = NULL;
            return newHead;
        }
    
        bool isPalindrome(ListNode* head) {
            if(head == NULL || head->next == NULL) return true;
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast->next != NULL && fast->next->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode* newHead = reverseList(slow->next);
            ListNode* second = newHead;
            ListNode* checker = head;
    
            while(second != NULL){
                if(checker->val != second->val){
                    reverseList(newHead);
                    return false;
                }
                checker = checker->next;
                second = second->next;
            }
    
            reverseList(newHead);
            return true;
        }
    };