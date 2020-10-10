//
// Created by Samuel Vieira on 06/10/20.
//

#include <string>
#include <iostream>

struct Info {
public:
    long key;
    std::string fechaHora;
    std::string mensajeError;
    void print();
};

void Info::print() {
    std::cout << key << " " << fechaHora << " " << mensajeError << std::endl;
}

#ifndef ACT_23_DOUBLELINKEDLIST_NODE_H
#define ACT_23_DOUBLELINKEDLIST_NODE_H

class Node {
public:
    Node (Info data);
    Node (Info data, Node *next, Node *prev);
    Info getData();
    Node* getNext();
    Node* getPrev();
    void setData(Info data);
    void setNext(Node *next);
    void setPrev(Node *prev);

private:
    Info data;
    Node *next;
    Node *prev;
};

// Complejidad O(1)
Node::Node(Info data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

// Complejidad O(1)
Node::Node(Info data, Node *next, Node *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}

// Complejidad O(1)
Info Node::getData() {
    return this->data;
}

// Complejidad O(1)
Node* Node::getNext() {
    return next;
}

// Complejidad O(1)
Node* Node::getPrev() {
    return prev;
}

// Complejidad O(1)
void Node::setData(Info data) {
    this->data = data;
}

// Complejidad O(1)
void Node::setNext(Node *next) {
    this->next = next;
}

// Complejidad O(1)
void Node::setPrev(Node *prev) {
    this->prev = prev;
}
#endif //ACT_23_DOUBLELINKEDLIST_NODE_H