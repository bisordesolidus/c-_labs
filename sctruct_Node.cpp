#include <iostream>

struct Node {
    int key;
    Node* next;

    Node() : key(0), next(nullptr) {}
};

void push_front(Node*& head_ref, int new_key) {
    Node* new_node = new Node();
    new_node->key = new_key;
    new_node->next = head_ref;
    head_ref = new_node;
};

void push_back(Node*& head_ref, int new_key) {
    Node* new_node = new Node();
    new_node->key = new_key;
    new_node->next = nullptr;

    if (head_ref == nullptr) {
        head_ref = new_node;
    }
    else {
        Node* current = head_ref;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
};

void insert_after(Node*& prev_ref, int new_key) {
    if (prev_ref == nullptr) {
        return;
    }
    Node* new_node = new Node();
    new_node->key = new_key;

    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
};

void destroy_list(Node*& head_ref) {
    Node* current = head_ref;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head_ref = nullptr;
};

void print_list(Node* head_ref) {
    if (head_ref == nullptr) {
        std::cout << std::endl;
        return;
    }

    Node* current = head_ref;

    while (current != nullptr) {
        std::cout << current->key;
        if (current->next != nullptr) {
            std::cout << " ";
        }
        else {
            std::cout << std::endl;
        }
        current = current->next;
    }
};

Node* find(Node* head_ref, int key) {
    Node* current = head_ref;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
};

void remove_key(Node*& head_ref, int key) {
    Node* temp = head_ref;
    Node* prev = NULL;
    while (temp != NULL and temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (prev == NULL) {
        head_ref = temp->next;
    }
    else {
        prev->next = temp->next;
        head_ref = prev;
    }
    delete temp;
};