#include "Tamanho.hpp"
#include "Offset.hpp"
#include <cstdlib>
#include <time.h>

Tamanho::Tamanho() //inicialia tamanho
{
    this->x = 0;
    this->y = 0;
}

Tamanho::Tamanho(int x, int y) //define que x eh x e y eh y
{
    this->x = x;
    this->y = y;
}

int Tamanho::getX() //pega o tamanho de x
{
    return x;
}

int Tamanho::getY() //pega o amanho de y
{
    return y;
}

int Tamanho::getArea() { //pega a area que x e y formam
    return x * y;
}

bool Tamanho::contem(Offset offset) //o contem verifica se o offset de x e de y é menor que x e y
{                                    //e apenas retorna esse x valido e esse y valido
    bool xValido = offset.getX() < x;
    bool yValido = offset.getY() < y;
    return xValido && yValido;
}

bool Tamanho::operator >(Tamanho tamanho)//gera o operador maior que e retorna se a a area que ele pegou eh
{                                        //maior que o tamanho dela, se for falso ela ira trancar ai mesmo
    return getArea() > tamanho.getArea();//o mesmo foi feito para todos os operadores
}

bool Tamanho::operator <(Tamanho tamanho)
{
    return getArea() < tamanho.getArea();
}

bool Tamanho::operator >=(Tamanho tamanho)
{
    return getArea() >= tamanho.getArea();
}

bool Tamanho::operator <=(Tamanho tamanho)
{
    return getArea() <= tamanho.getArea();
}

bool Tamanho::operator ==(Tamanho tamanho)
{
    return (x == tamanho.x) && (y == tamanho.y);
}

bool Tamanho::operator !=(Tamanho tamanho)
{
    return (x != tamanho.x) || (y != tamanho.y);
}

ostream& operator <<(ostream& os, Tamanho& dt) { //nao entendi essa
    os << dt.getX() << "x" << dt.getY();
    return os;
}
