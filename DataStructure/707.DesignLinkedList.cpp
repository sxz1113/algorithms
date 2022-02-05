#include "../Common.h"

 
class Node {
public:
    int val;
    Node *next;
    
    Node(int _val) {
        val = _val;
        next = NULL;
    }
};

class MyLinkedList {
private:
    // keep track of linked list size
    int size_ = 0;
    // dummy head
    Node *head_ = new Node(0);

public:
    int size() {
        return size_;
    }

    MyLinkedList() {
    }
    
    int get(int index) {
        if (index > size_)
            return -1;

        Node *cur = head_->next;
        for (int i = 0; i < index; ++i)
            cur = cur->next;

        return cur->val;
    }
    
    void addAtHead(int val) {
        Node *node = head_->next;
        head_->next = new Node(val);
        head_->next->next = node;
        ++size_;
        print();
    }
    
    void addAtTail(int val) {
        Node *cur = head_;
        while (cur->next)
            cur = cur->next;

        // Node node = Node(val);
        cur->next = new Node(val);
        ++size_;
        print();
    }
    
    void addAtIndex(int index, int val) {
        if (index > size_)
            return;

        Node *cur = head_, 
             *next = nullptr;
        for (int i = 0; i < index; ++i)
            cur = cur->next;

        // Node node = Node(val);
        next = cur->next;
        cur->next = new Node(val);
        cur->next->next = next;
        // node.next = next;
        ++size_;
        print();
    }
    
    void deleteAtIndex(int index) {
        if (index > size_)
            return;
    
        Node *cur = head_, 
             *next_ = nullptr;

        for (int i = 0; i < index; ++i)
            cur = cur->next;

        next_ = cur->next;
        cur->next = next_->next;
        next_->next = nullptr;
        delete next_;
        --size_;
        print();
    }

    void print() {
        Node *cur = head_;
        while (head_) {
            printf("%d -> ", cur->val);
            cur = cur->next;
        }
        printf(" null \n");
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, char const *argv[]) {
    MyLinkedList linked_list = MyLinkedList();
    linked_list.addAtHead(1);
    linked_list.addAtTail(3);
    linked_list.addAtIndex(1, 2);
    cout << linked_list.get(1) << endl;
    linked_list.deleteAtIndex(1);
    // linked_list.get(1);
    return 0;
}
