//
// Created by Samuel Vieira on 06/10/20.
//
#include "Node.h"

#include <iostream>
#include <fstream>
#ifndef ACT_23_DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
#define ACT_23_DOUBLELINKEDLIST_DOUBLELINKEDLIST_H

class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    int getSize();
    void addFirst(Info data);
    void addLast(Info data);
    void print();
    void sort();
    void search(long begin, long end);
    void deleteAll();
    void sendToFile();
private:
    Node *head;
    Node *tail;
    int size;
};

// Complejidad O(1)
DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// Complejidad O(n)
DoubleLinkedList::~DoubleLinkedList() {
    deleteAll();
}

// Complejidad O(1)
int DoubleLinkedList::getSize() {
    return size;
}

// Complejidad O(1)
void DoubleLinkedList::addFirst(Info data) {
    if (size == 0) {
        Node *newNode = new Node(data);
        head = tail = newNode;
        size++;
    } else {
        Node *newNode = new Node(data, head, nullptr);
        head->setPrev(newNode);
        head = newNode;
        size++;
    }
}

// Complejidad O(1)
void DoubleLinkedList::addLast(Info data) {
    if (size == 0) {
        addFirst(data);
        size++;
    } else {
        Node *newNode = new Node(data, nullptr, tail);
        tail = tail->getNext();
        size++;
    }
}

void DoubleLinkedList::print() {
    Node *curr = head;
    while (curr != nullptr) {
        Info aux = curr->getData();
        aux.print();
        curr = curr->getNext();
    }
}

// Complejidad O(n^2)
void DoubleLinkedList::sort() {
    bool flag = true;
    for (int i = 0; i < size - 1 && flag; i++) {
        flag = false;
        Node *valueA = head;
        Node *valueB = head->getNext();
        for (int j = 0; j < size - i - 1; j++) {
            if (valueA->getData().key > valueB->getData().key) {
                Info temp = valueB->getData();
                valueB->setData(valueA->getData());
                valueA->setData(temp);
                flag = true;
            }
            valueA = valueB;
            valueB = valueB->getNext();
        }
    }
}

// Complejidad O(n)
void DoubleLinkedList::search(long begin, long end) {
    Node *curr = head;

    while (curr != nullptr) {
        if (curr->getData().key > begin && curr->getData().key <= end) {
            curr->getData().print();
        }
        curr = curr->getNext();
    }
}

// Complejidad O(n)
void DoubleLinkedList::deleteAll() {
    while (head != nullptr) {
        Node *aux = head;
        head = head->getNext();
        delete aux;
    }
}

// Complejidad O(n)
void DoubleLinkedList::sendToFile() {
    Node *curr = head;
    std::ofstream outfile("salida.txt");

    while (curr != nullptr) {
        long key = curr->getData().key;
        std::string date = curr->getData().fechaHora;
        std::string error = curr->getData().mensajeError;

        outfile << key << " " << date << " " << error << std::endl;

        curr = curr->getNext();
    }
}
#endif //ACT_23_DOUBLELINKEDLIST_DOUBLELINKEDLIST_H