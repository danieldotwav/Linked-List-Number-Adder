// Question: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

// Actual algorithm to sum the linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

// Utility functions to create a new linked list from an integer array
ListNode* createList(const vector<int>& nums);
void printList(ListNode* head);

// Utility function to free DMA
void freeList(ListNode* head);

int main() {
    // Test Case 1: Both numbers have the same number of digits.
    ListNode* l1 = createList({ 2, 4, 3 }); // Represents 342
    ListNode* l2 = createList({ 5, 6, 4 }); // Represents 465
    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Test Case 1: ";
    printList(result); // Expected Output: 7 -> 0 -> 8 (Represents 807)
    // Free Dynamically Allocated Memory
    freeList(l1);
    freeList(l2);
    freeList(result);

    // Test Case 2: Numbers with different number of digits.
    l1 = createList({ 1 }); // Represents 10
    l2 = createList({ 1, 2 }); // Represents 210
    result = addTwoNumbers(l1, l2);
    cout << "Test Case 2: ";
    printList(result); // Expected Output: 0 -> 2 -> 2 (Represents 220)
    // Free Dynamically Allocated Memory
    freeList(l1);
    freeList(l2);
    freeList(result);

    // Test Case 3: Adding zeros.
    l1 = createList({ 1 }); // Represents 0
    l2 = createList({ 1 }); // Represents 0
    result = addTwoNumbers(l1, l2);
    cout << "Test Case 3: ";
    printList(result); // Expected Output: 0 (Represents 0)
    // Free Dynamically Allocated Memory
    freeList(l1);
    freeList(l2);
    freeList(result);

    // Test Case 4: Large numbers.
    l1 = createList({ 9, 9, 9, 9, 9, 9, 9 }); // Represents 9999999
    l2 = createList({ 9, 9, 9, 9 }); // Represents 9999
    result = addTwoNumbers(l1, l2);
    cout << "Test Case 4: ";
    printList(result); // Expected Output: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1 (Represents 10009998)

    // Free Dynamically Allocated Memory
    freeList(l1);
    freeList(l2);
    freeList(result);

	return 0;
}

// Algorithm
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy_head(0);
    ListNode* current = &dummy_head;
    int carry = 0;

    // Loop through lists until both are empty and there is no carry
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        // Add and move the l1 and l2 pointers
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Compute the new carry and sum
        carry = sum / 10;

        // Create a new node for the digit
        current->next = new ListNode(sum % 10);

        // Push the sum pointer forward
        current = current->next;
    }
    return dummy_head.next;
}

ListNode* createList(const vector<int>& nums) {
    ListNode dummy_head(0);
    ListNode* current = &dummy_head;

    for (int val : nums) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy_head.next;
}

void printList(ListNode* head) {
    // In C++, a 'null' pointer is implicitly convertible to 'false'
    // Any non-null pointer is convertible to 'true'
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}