// Definition of linked list:
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// Using Hashing
int lengthOfLoop(Node *head) {
    // Write your code here
    unordered_map<Node*, int> mpp;
    Node* temp = head;

    int timer = 0;
    while(temp!=NULL){
        if(mpp.find(temp) != mpp.end()){
            return timer-mpp[temp];
        }
        mpp[temp]= timer;
        timer++;

        temp=temp->next;
    }
    return 0;
}

// Using Tortoise And Hare Method
int lengthOfLoop(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        int cnt = 0;
        if(slow == fast){
            fast = fast->next;
            cnt++;

            while(slow != fast){
                fast = fast->next;
                cnt++;    
            }
            return cnt;
        }
    }
    return 0;
}
