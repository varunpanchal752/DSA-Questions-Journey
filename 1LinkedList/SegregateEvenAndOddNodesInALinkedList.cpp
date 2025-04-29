// Definition for linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};


Node* segregateEvenOdd(Node* head)
{
    if(head == NULL || head->next == NULL) return head;
    // Write your code here
    Node* evenHead = new Node(-1);
    Node* oddHead = new Node(-1);
    Node* evenTail = evenHead;
    Node* oddTail = oddHead;

    Node* temp, *cur = head;
    while(cur != NULL){
        temp = cur;
        cur = cur->next;
        temp->next = NULL;

        if(temp->data % 2 == 1){
            oddTail->next = temp;
            oddTail = temp;
        }
        else{
            evenTail->next = temp;
            evenTail = temp;
        }
    }

    evenTail->next = oddHead->next;
    head = evenHead->next;

    return head;
}
