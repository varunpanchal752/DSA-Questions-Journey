// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    public:
        ListNode* findKthNode(ListNode* temp, int k){
            int cnt = 1;
            while(temp != NULL){
                if(cnt == k) return temp;
                cnt++;
                temp = temp->next;
            }
            return temp;
        }
    
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL || head->next == NULL || k == 0) return head;
    
            ListNode* tail = head; 
            int length = 1;
            while(tail->next != NULL){
                tail = tail->next;
                length++;
            }
    
            if(k%length == 0) return head;
            k = k % length;
    
            tail->next = head;
            ListNode* newLastNode = findKthNode(head, length - k);
            
            head = newLastNode->next;
            newLastNode->next = NULL;
    
            return head;     
        }
    };