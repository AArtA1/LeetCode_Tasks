#include <iostream>
#include <deque>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


bool isPalindrome(ListNode *head) {
    std::deque<int> deque;
    auto current = head;
    while(current != nullptr){
        deque.push_front(current->val);
        current = current->next;
    }
    while(deque.size() > 1){
        auto left = deque.back();
        auto right = deque.front();
        if(left != right){
            return false;
        }
        deque.pop_back();
        deque.pop_front();
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
