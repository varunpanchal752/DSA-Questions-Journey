#include <bits/stdc++.h>

void insertIntoStack(stack<int> &stack, int element){
	if(stack.empty() || stack.top() < element){
		stack.push(element);
		return;
	}
	int top = stack.top();
	stack.pop();
	insertIntoStack(stack, element);
	stack.push(top);  // Push top back after inserting
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty() || stack.size() == 1) return;

	int top = stack.top();
	stack.pop();
	sortStack(stack);  // Sort the remaining stack
	insertIntoStack(stack, top);  // Insert top into correct position
	return;
}