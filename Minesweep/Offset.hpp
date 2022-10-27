#ifndef OFFSET_HPP_INCLUDED
#define OFFSET_HPP_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;
class Tamanho;
template <typename T>
class Lista;

class Offset
{
    public:
        Offset();
        Offset(int x, int y);
        int getX();
        int getY();
        bool estaDentro(Tamanho tamanho);
        int distancia(Offset offset);
        Lista<Offset> envolta(int raio = 1);
        bool operator >(Offset offset);
        bool operator <(Offset offset);
        bool operator >=(Offset offset);
        bool operator <=(Offset offset);
        bool operator ==(Offset offset);
        bool operator !=(Offset offset);
    protected:
        int x;
        int y;
};

ostream& operator <<(ostream& os, Offset& dt);

#endif // OFFSET_HPP_INCLUDED
