#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    if(head == nullptr){
        return nullptr;
    }
    if(head->next == nullptr){
        return head;
    }
    ListNode* current = head->next;
    ListNode* previous = head;
    previous->next = nullptr;
    while(current != nullptr){
        auto next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    reverseList(head);
}
