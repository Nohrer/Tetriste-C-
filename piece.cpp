#include "piece.hpp"

Piece::Piece(char s, int c) {
    shape = s;
    color = c;
}

Piece::Piece() {
    shape = '\0';
    color = 0;
}

char Piece::getShape() {
    return shape;
}

int Piece::getColor() {
    return color;
}

void Piece::toString() {
    std::cout << shape << color;
}