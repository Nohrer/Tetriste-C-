#include "node.hpp"

Node::Node(Piece p) {
    data = p;
    next = NULL;
    prev = NULL;
}

Piece Node::getData() {
    return data;
}

void Node::setData(Piece p) {
    data = p;
}

void Node::setNext(Node* n) {
    next = n;
}

void Node::setPrev(Node* p) {
    prev = p;
}

Node* Node::getNext() const {
    return next;
}

Node* Node::getPrev() const {
    return prev;
}