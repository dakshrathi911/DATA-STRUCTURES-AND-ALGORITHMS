#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;

    SinglyLinkedList() {
        this->head = nullptr;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        delete temp;
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    // Create a new node with the given data
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the list
    SinglyLinkedListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Attach the new node to the end
    current->next = newNode;
    return head;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->head = insertNodeAtTail(llist->head, llist_item);
    }

    print_singly_linked_list(llist->head, "\n", fout);
    fout << "\n";

    free_singly_linked_list(llist->head);

    fout.close();

    return 0;
}
