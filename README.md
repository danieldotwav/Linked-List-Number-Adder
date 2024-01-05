# Linked List Number Adder

This C++ project implements an algorithm to add two numbers represented as reverse-ordered linked lists. Each node of the linked list contains a single digit, and the digits are stored in reverse order.

## Problem Statement

Given two non-empty linked lists representing two non-negative integers, where the digits are stored in reverse order, the task is to add these two numbers and return the sum as a linked list.

## Algorithm

The `addTwoNumbers(ListNode* l1, ListNode* l2)` function is the core of this project, where the numbers represented by linked lists `l1` and `l2` are added.

### Logic

1. **Initialization**: A dummy head node is used to simplify list operations. A carry variable is initialized to 0.
2. **Traversal**: Iterate through both lists simultaneously while handling any carry from the previous addition.
3. **Addition**: For each pair of nodes, sum the digits along with the carry. Update the carry for the next iteration.
4. **Node Creation**: Create a new node with the digit part of the sum and add it to the resulting list.
5. **Carry Handling**: After traversing both lists, if there is a remaining carry, it is added as a new node to the result list.

### Time Complexity

- **O(max(n, m))**: Here, `n` and `m` represent the lengths of the two input lists. The complexity is linear to the length of the longer list.

### Space Complexity

- **O(max(n, m))**: The length of the new list is at most `max(n, m) + 1` (due to a potential carry).

### Potential Improvements

- **Optimized Memory Management**: Implement advanced memory handling techniques, especially for large lists.
- **Alternative Implementations**: Exploring different methods, such as a recursive approach, could provide educational insights, though they might not improve efficiency.

## Utility Functions

- `createList(const vector<int>& nums)`: Generates a linked list from a vector of integers.
- `printList(ListNode* head)`: Outputs the linked list to the console.
- `freeList(ListNode* head)`: Frees dynamically allocated memory of the list.

## Test Cases

Included in the `main` function are several test cases demonstrating the algorithm:

1. Numbers with equal lengths.
2. Numbers with unequal lengths.
3. Cases involving zero.
4. Large numbers.

## Usage

Compile and run the C++ file to observe the algorithm in action with the provided test cases.

## Contributions

Contributions are welcome. Feel free to fork the repository, suggest improvements, or add additional test cases.
