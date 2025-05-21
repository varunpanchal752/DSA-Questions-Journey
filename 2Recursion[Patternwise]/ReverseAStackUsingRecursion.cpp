void insertAtBottom(stack<int> &stack, int element){
    if(stack.empty()) {
        stack.push(element);
        return;
    } 

    int top = stack.top();
    stack.pop();
    insertAtBottom(stack, element);
    stack.push(top);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty() || stack.size() == 1) return;

    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, top);
}