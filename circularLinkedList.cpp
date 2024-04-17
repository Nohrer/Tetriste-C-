#include "circularLinkedList.hpp"

CircularLinkedList::CircularLinkedList() {
    head = NULL;
}

CircularLinkedList::~CircularLinkedList() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current->getNext();
        delete current;
        current = temp;
    }
}

Node* CircularLinkedList::getHead() const {
    return head;
}

void CircularLinkedList::append(Piece p) {
    Node* new_node = new Node(p);
    if (head == NULL) {
        head = new_node;
        new_node->setNext(new_node);
        new_node->setPrev(new_node);
    }
    else {
        Node* last = head->getPrev();

        new_node->setNext(head);
        new_node->setPrev(last);
        last->setNext(new_node);
        head->setPrev(new_node);
    }
}

void CircularLinkedList::insert(Piece p) {
    Node* new_node = new Node(p);
    if (head == NULL) {
        head = new_node;
        new_node->setNext(new_node);
        new_node->setPrev(new_node);
    }
    else {
        new_node->setNext(head);
        new_node->setPrev(head->getPrev());
        head->getPrev()->setNext(new_node);
        head->setPrev(new_node);
        head = new_node;
    }
}

void CircularLinkedList::deleteNode(Node* n) {
    if (head == n) {
        if (head->getNext() == head) {
            delete head;
            head = NULL;
            return;
        }

        head->getPrev()->setNext(head->getNext());
        head->getNext()->setPrev(head->getPrev());
        Node* temp = head;
        head = head->getNext();
        delete temp;
        return;
    }

    Node* current = head->getNext();
    while (current != head) {
        if (current == n) {
            current->getNext()->setPrev(current->getPrev());
            current->getPrev()->setNext(current->getNext());
            delete current;
            break;
        }
        current = current->getNext();
    }
}

int CircularLinkedList::turnRight(char c, int cOs) {
    if (head == NULL || head->getNext() == head) {
        return 0;
    }

    std::vector<Node*> DL;
    int dlSize = 0;
    Node* current = head;
    do {
        if ((cOs == 0 && current->getData().getShape() == c) || (cOs == 1 && current->getData().getColor() == c)) {
            DL.push_back(current);
            dlSize++;
        }
        current = current->getNext();
    } while (current != head);

    for (std::vector<int>::size_type i = 1; i < dlSize; i++) {
        Piece temp = DL[i]->getData();
        DL[i]->setData(DL[i - 1]->getData());
        DL[i - 1]->setData(temp);
    }

    current = head;
    int index = 0;
    do {
        if ((cOs == 0 && current->getData().getShape() == c) || (cOs == 1 && current->getData().getColor() == c)) {
            current->setData(DL[index]->getData());
            index++;
        }
        current = current->getNext();
    } while (current != head);

    DL.clear();
    return 1;
}

int CircularLinkedList::turnLeft(char c, int cOs) {
    if (head == NULL || head->getNext() == head) {
        return 0;
    }

    std::vector<Node*> DL;
    int dlSize = 0;
    Node* current = head;
    do {
        if ((cOs == 0 && current->getData().getShape() == c) || (cOs == 1 && current->getData().getColor() == c)) {
            DL.push_back(current);
            dlSize++;
        }
        current = current->getNext();
    } while (current != head);

    for (std::vector<int>::size_type i = dlSize - 1; i > 0; i--) {
        Piece temp = DL[i]->getData();
        DL[i]->setData(DL[i - 1]->getData());
        DL[i - 1]->setData(temp);
    }

    current = head;
    int index = 0;
    do {
        if ((cOs == 0 && current->getData().getShape() == c) || (cOs == 1 && current->getData().getColor() == c)) {
            current->setData(DL[index]->getData());
            index++;
        }
        current = current->getNext();
    } while (current != head);

    DL.clear();
    return 1;
}

void CircularLinkedList::printList() const {
    if (head == NULL) {
        return;
    }

    Node* current = head;
    int index = 0;

    do {
        int colorCode = current->getData().getColor();
        std::cout << "\033[3" << colorCode << "m";
        std::cout << current->getData().getShape() << " ";
        std::cout << "\033[0m";
        current = current->getNext();
        index++;
    } while (current != head);

    std::cout << std::endl;
}

int CircularLinkedList::length() {
    if (head == NULL) {
        return 0;
    }

    int count = 1;
    Node* current = head->getNext();
    while (current != head) {
        count++;
        current = current->getNext();
    }
    return count;
}