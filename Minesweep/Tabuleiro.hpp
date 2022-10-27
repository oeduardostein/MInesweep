#include <iostream>
#include <cstring>
using namespace std;

#ifndef TABULEIRO_HPP_INCLUDED
#define TABULEIRO_HPP_INCLUDED

#include "Tamanho.hpp"
#include "Lista.hpp"
class Bomba;
class Offset;

class Tabuleiro
{
    public:
        Tabuleiro();
        Tabuleiro(Tamanho tamanho, int quantidadeDeBombas);
        void novoJogo(Tamanho tamanho, int quantidadeDeBombas);
        void novoJogo();
        int operator [](Offset offset);
        bool operator ==(Tabuleiro tabuleiro);
        bool operator !=(Tabuleiro tabuleiro);
        string toString();
    protected:
        Tamanho tamanho;
        Lista<Bomba> bombas;
        Lista<Offset> abertos;
        int dadoEm(Offset offset);
        int bombasAoRedor(Offset offset);
};

ostream& operator <<(ostream& os, Tabuleiro& dt);

#endif // TABULEIRO_HPP_INCLUDED
