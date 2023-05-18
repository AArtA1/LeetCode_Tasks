#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void add(int value) {
        if (next == nullptr) {
            next = new ListNode(value);
            return;
        }
        auto curr = next;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new ListNode(value);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto temp = new ListNode();
    temp->next = head;

    ListNode *fast = temp;
    ListNode *slow = temp;

    for (int i = 1; i <= n; i++) {
        fast = fast->next;
    }

    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *del = slow->next;
    slow->next = slow->next->next;
    delete (del);

    return temp->next;
}

int main() {
    ListNode *list = new ListNode(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    removeNthFromEnd(list, 2);
    std::cout << 1;
}
