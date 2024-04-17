#ifndef NODE_HPP
#define NODE_HPP

#include "piece.hpp"

class Node {
    Piece data;
    Node* next;
    Node* prev;

public:
    Node(Piece p);
    Piece getData();
    void setData(Piece p);
    void setNext(Node* n);
    void setPrev(Node* p);
    Node* getNext() const;
    Node* getPrev() const;
};

#endif