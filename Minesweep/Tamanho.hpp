#ifndef TAMANHO_HPP_INCLUDED
#define TAMANHO_HPP_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;
#include "Offset.hpp"

class Tamanho : public Offset {
    public:
        Tamanho();
        Tamanho(int x, int y);
        int getX();
        int getY();
        int getArea();
        bool contem(Offset tamanho);
        bool operator >(Tamanho tamanho);
        bool operator <(Tamanho tamanho);
        bool operator >=(Tamanho tamanho);
        bool operator <=(Tamanho tamanho);
        bool operator ==(Tamanho tamanho);
        bool operator !=(Tamanho tamanho);
};

ostream& operator <<(ostream& os, Tamanho& dt);

#endif // TAMANHO_HPP_INCLUDED
