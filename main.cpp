#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "piece.hpp"
#include "node.hpp"
#include "circularLinkedList.hpp"

using namespace std;

static int score = 0;

const int colors[] = { 1, 2, 3, 4 };
const char shapes[] = { 'a', 'b', 'c', 'd' };

Piece generatePiece() {
    int c = rand() % 4;
    int s = rand() % 4;
    Piece piece(shapes[s], colors[c]);
    return piece;
}

void startGame(CircularLinkedList* lc) {
    for (int i = 0; i < 1; i++) {
        Piece p = generatePiece();
        lc->append(p);
    }
}

void check(CircularLinkedList* lc) {
    Node* current = lc->getHead();
    if (current == NULL) {
        cout << "You win" << endl;
        startGame(lc);
        return;
    }
    if (lc->length() < 3) {
        return;
    }
    Node* originalHead = lc->getHead();
    do {
        if (current->getData().getShape() == current->getNext()->getData().getShape() && current->getNext()->getData().getShape() == current->getNext()->getNext()->getData().getShape()) {
            lc->deleteNode(current->getNext()->getNext());
            lc->deleteNode(current->getNext());
            lc->deleteNode(current);
            score++;
            break;
        }

        if (current->getData().getColor() == current->getNext()->getData().getColor() && current->getNext()->getData().getColor() == current->getNext()->getNext()->getData().getColor()) {
            lc->deleteNode(current->getNext()->getNext());
            lc->deleteNode(current->getNext());
            lc->deleteNode(current);
            score++;
            break;
        }
        current = current->getNext();
    } while (current != originalHead);
}

void RotateBasedOnUserInput(CircularLinkedList& plateau, char usrInpt) {
    if (usrInpt == 'c' || usrInpt == 'C') {
        cout << "Enter the color you want to rotate: (1:red,2:green,3:yellow,4:orange)" << endl;
        char color = _getch();
        cout << "Enter 0 to rotate left | 1 to rotate right" << endl;
        char rOrL = _getch();
        if (rOrL == '0') {
            plateau.turnLeft(color, 1);
        }
        else if (rOrL == '1') {
            plateau.turnRight(color, 1);
        }
    }
    else if (usrInpt == 's' || usrInpt == 'S') {
        cout << "Enter the shape you want to rotate: (a,b,c,d)" << endl;
        char shape = _getch();
        cout << "Enter 0 to rotate left | 1 to rotate right" << endl;
        char rOrL = _getch();
        if (rOrL == '0') {
            plateau.turnLeft(shape, 0);
        }
        else if (rOrL == '1') {
            plateau.turnRight(shape, 0);
        }
    }
    else {
        cout << "Invalid input" << endl;
    }
}

int main() {
    system("color 07");
    srand(time(NULL));
    system("cls");
    cout << " __        __   _                            _          _____    _        _     _       " << endl;
    cout << " \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   |_   _|__| |_ _ __(_)___| |_ ___ " << endl;
    cout << "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\    | |/ _ \\ __| '__| / __| __/ _ \\" << endl;
    cout << "   \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |   | |  __/ |_| |  | \\__ \\ ||  __/" << endl;
    cout << "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/    |_|\\___|\\__|_|  |_|___/\\__\\___|" << endl;
    cout << "\n\n Presse any button to run the game:\n";
    getch();
    system("cls");
    CircularLinkedList plateau = CircularLinkedList();
    startGame(&plateau);

    while (true) {
        check(&plateau);
        Sleep(600);
        if (plateau.length() > 12) {
            system("cls");
            cout << "You lose" << endl;
            cout << "Your score: " << score << endl;
            break;
        }
        system("cls");
        cout << "Your score: " << score << endl;
        plateau.printList();
        Piece nextPiece = generatePiece();

        cout << "\nnext piece: ";

        cout << "\033[3" << nextPiece.getColor() << "m";
        cout << nextPiece.getShape() << " ";
        cout << "\033[0m";
        cout << endl;
        cout << "Click Q to place it left | D to place it right | R to rotate \n";
        cout << "Click Esc to quit the game \n";

        char order;
        order = _getch();
        if (order == 'd' || order == 'D') {
            plateau.append(nextPiece);
        }
        else if (order == 'q' || order == 'Q') {
            plateau.insert(nextPiece);
        }
        else if (order == 'r' || order == 'R') {
            cout << "Click C to rotate based on color | S to rotate based on shape \n";
            char usrInpt;
            usrInpt = _getch();
            RotateBasedOnUserInput(plateau, usrInpt);
        }
        else if (order == 27) {
            break;
        }
    }

    return 0;
}