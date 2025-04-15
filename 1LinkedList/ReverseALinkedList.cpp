// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode next) : val(x), next(next) {}
};

// Iterative 
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head == nullptr || head->next == nullptr) return head;
    
            ListNode* cur=head;
            ListNode* back = NULL;
    
            while(cur != nullptr){
                ListNode* front = cur->next;
                cur->next=back;            
                back = cur;
                cur = front;
            }
    
            return back;
        }
    };


// Recursive
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head == nullptr || head->next == nullptr) return head;
    
            ListNode* newHead = reverseList(head->next); 
    
            ListNode* front = head->next;
    
            front->next = head;
    
            head->next = NULL;
            
            return newHead;
        }
};