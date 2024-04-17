#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP
#include <vector>
#include "node.hpp"

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList();
    ~CircularLinkedList();
    Node* getHead() const;
    void append(Piece p);
    void insert(Piece p);
    void deleteNode(Node* n);
    int turnRight(char c, int cOs);
    int turnLeft(char c, int cOs);
    void printList() const;
    int length();
};

#endif