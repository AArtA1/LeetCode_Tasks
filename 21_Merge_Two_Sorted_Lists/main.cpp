#include <iostream>


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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto curr = new ListNode(-1);
    auto node = curr;
    //node->next = curr;
    auto first = list1;
    auto second = list2;
    while(first != nullptr || second!= nullptr){
        if(first == nullptr){
            curr->next = new ListNode(second->val);
            curr = curr->next;
            second = second->next;
            continue;
        }
        if(second == nullptr){
            curr->next = new ListNode(first->val);
            curr = curr->next;
            first = first->next;
            continue;
        }
        if(first->val < second->val){
            curr->next = new ListNode(first->val);
            first = first->next;
        }
        else{
            curr->next = new ListNode(second->val);
            second = second->next;
        }
        curr = curr->next;
    }
    auto temp = node;
    node = node->next;
    delete temp;
    return node;
}


int main() {
    ListNode *list = new ListNode(1);
    list->add(2);
    list->add(4);
    ListNode* list2 = new ListNode(1);
    list2->add(3);
    list2->add(4);
    auto n = mergeTwoLists(list, list2);
    std::cout << 1;
}
