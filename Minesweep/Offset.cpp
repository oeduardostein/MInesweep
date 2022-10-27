#include "Offset.hpp"
#include "Tamanho.hpp"
#include "Lista.cpp"
#include <cstdlib>

Offset::Offset() //inicializa o offset
{
    x = 0;
    y = 0;
}

Offset::Offset(int x, int y) //somente coloca o x como x e o y como y
{
    this->x = x;
    this->y = y;
}

int Offset::getX() //o getX pega o x e retorna ele mesmo 
{
    return x;
}

int Offset::getY() //o gety pega o y e retorna ele mesmo
{
    return y;
}

bool Offset::estaDentro(Tamanho tamanho) { //esta funcao verifica se la dentro do tamanho contem este offset
    tamanho.contem(Offset(x, y));          //se nao conter ela retorna falso e tranca tudo
}

int Offset::distancia(Offset offset) { //nao entendi
    int dx = x - offset.getX();
    int dy = y - offset.getY();
    return (abs(dx) > abs(dy)) ? dx : dy;
}

Lista<Offset> Offset::envolta(int raio) { //nao entendi
    Lista<Offset> lista;
    for (int x = getX() - raio; x <= getX() + raio; x++) {
        for (int y = getY() - raio; y <= getY() + raio; y++) {
            Offset offset = Offset(x, y);
            if (offset != Offset(x, y)) lista.adicionar(offset);
        }
    }
    return lista;
}

bool Offset::operator >(Offset offset) //mesmos operadores de tamanho
{
    return (x > offset.x && y > offset.y);
}

bool Offset::operator <(Offset offset)
{
    return (x < offset.x && y < offset.y);
}

bool Offset::operator >=(Offset offset)
{
    return (x >= offset.x && y >= offset.y);
}

bool Offset::operator <=(Offset offset)
{
    return (x <= offset.x && y <= offset.y);
}

bool Offset::operator ==(Offset offset)
{
    return (x == offset.x) && (y == offset.y);
}

bool Offset::operator !=(Offset offset)
{
    return (x != offset.x) || (y != offset.y);
}

ostream& operator <<(ostream& os, Offset& dt) {//nao entendi
    os << "(" << dt.getX() << ", " << dt.getY() << ")";
    return os;
}
