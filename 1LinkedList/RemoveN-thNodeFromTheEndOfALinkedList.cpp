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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        
        ListNode* temp = head;

        int listLen = 0;
        while(temp != NULL){
            listLen++;
            temp = temp->next;
        }

        if(listLen == n){
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }

        int nodeInd = listLen - n;
        temp = head;
        while(temp != NULL){
            nodeInd--;
            if(nodeInd == 0) break; 
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);

        return head; 
    }
};

// Optimal
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head == NULL) return NULL;
            
            ListNode* slow = head;
            ListNode* fast = head;
    
            int cnt = 0;
            while(cnt != n){
                fast = fast->next;
                cnt++;
            }
    
            if(fast == NULL){
                ListNode* newHead = head->next;
                delete(head);
                return newHead;
            }
    
            while(fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }
    
            ListNode* delNode = slow->next;
            slow->next = slow->next->next;
            delete(delNode);
    
            return head; 
        }
    };