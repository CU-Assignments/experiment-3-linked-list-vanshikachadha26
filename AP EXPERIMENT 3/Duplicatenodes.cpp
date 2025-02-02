#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        // Traverse the list
        while (current->next != nullptr && current->next->next != nullptr) {
            if (current->next->val == current->next->next->val) {
                // Found duplicates, move the pointer to skip all duplicates
                int duplicateValue = current->next->val;
                while (current->next != nullptr && current->next->val == duplicateValue) {
                    current->next = current->next->next;
                }
            } else {
                // No duplicates, move to the next node
                current = current->next;
            }
        }

        // Return the new head (dummy->next)
        return dummy->next;
    }

    // Helper function to print the list
    void printList(ListNode* head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    Solution solution;

    // Creating the sorted linked list: 1 -> 2 -> 2 -> 3 -> 4 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);

    // Deleting duplicates
    ListNode* result = solution.deleteDuplicates(head);

    // Printing the list after removing duplicates
    solution.printList(result);  // Output: 1 3
    return 0;
}
