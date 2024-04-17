#ifndef PIECE_HPP
#define PIECE_HPP
#include <iostream>
class Piece {
    char shape;
    int color;

public:
    Piece(char s, int c);
    Piece();
    char getShape();
    int getColor();
    void toString();
};

#endif