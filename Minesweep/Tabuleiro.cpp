#include "Tabuleiro.hpp"
#include "Enums.hpp"
#include "Tamanho.hpp"
#include "Lista.cpp"
#include <cstdlib>
#include <time.h>

Tabuleiro::Tabuleiro()//Construtor, onde temos um tamanho (é definido por x e y) e 
                      //e uma lista de bombas. Este construtor gera nosso tabuleiro.
{
    tamanho = Tamanho();
    bombas = Lista<Bomba>();
}

Tabuleiro::Tabuleiro(Tamanho tamanho, int quantidadeDeBombas)//Para começar um novo jogo devemos retornar 
{                                                            //um tamanho e uma quantidade de bombas
    novoJogo(tamanho, quantidadeDeBombas);
}

void Tabuleiro::novoJogo(Tamanho tamanho, int quantidadeDeBombas)
{
    this->tamanho = tamanho; //somente trazendo o tamanho para dentro desse metodo
    bombas = Lista<Bomba>(); //somente dizendo que a lista de bombas será usada aqui
    srand(time(NULL)); //zerando a srand
    for (int i = 0; i < quantidadeDeBombas; i++) //percorre todo i que eh menor que quantidade de bombas e
    {                                            //incrementa 1
        Offset offset = Offset(rand () % tamanho.getX(), rand () % tamanho.getY()); //nao sei explicar direito,
        Bomba bomba = Bomba(offset);                       //mas faz um sorteio de x e de y, coloca em bomba
        if (bombas.naoContem(bomba)) //testa se nao contem dentro de bombas
        {
            bombas.adicionar(bomba); //adiciona se não contem
        }
        else //se contem, ele soh incremente menos 1
        {
            i--;
        }
    }
}

void Tabuleiro::novoJogo() //reconstroi o tabuleiro com tamanho e bombas
{
    novoJogo(tamanho, bombas.getTamanho());
}

int Tabuleiro::operator [](Offset offset) //operadores
{
    int retorno = dadoEm(offset);
    if (retorno == 0) {
        abertos.adicionar(offset);
        Lista<Offset> lista = offset.envolta();
        for (int i = 0; i < lista.getTamanho(); i++) {
            (*this)[*lista[i]];
        }
    } else if (retorno > 0) {
        abertos.adicionar(offset);
    } else if (retorno == LocalDeBomba) {
        for (int x = 0; x < tamanho.getX(); x++) {
            for (int y = 0; y < tamanho.getY(); y++) {
                Offset novoOffset = Offset(x, y);
                if (abertos.naoContem(novoOffset)) {
                    abertos.adicionar(novoOffset);
                }
            }
        }
    }
    return retorno;
}

bool Tabuleiro::operator ==(Tabuleiro tabuleiro)
{
    return (tamanho == tabuleiro.tamanho && bombas == tabuleiro.bombas);
}

bool Tabuleiro::operator !=(Tabuleiro tabuleiro)
{
    return (tamanho != tabuleiro.tamanho || bombas != tabuleiro.bombas);
}

int Tabuleiro::dadoEm(Offset offset) //faz um teste se offset esta dentro do tamanho e se contem bomba
{                                    //no offset, retorna o local da bomba e retorna as bombas ao redor
    if (offset.estaDentro(tamanho))
    {
        if (bombas.contem(Bomba(offset))) return LocalDeBomba;
        return bombasAoRedor(offset);
    }
    return ForaDoLimite; //retorna ainda fora do limite, nao sei porque
}

int Tabuleiro::bombasAoRedor(Offset offset) //retorna o numero de bombas ao redor
{
    Lista<Offset> offsets = offset.envolta();
    int count = 0;
    for (int i = 0; i < bombas.getTamanho(); i++) {
        if (offsets.contem(bombas[i]->getOffset())) count++;
    }
    return count;
}

string Tabuleiro::toString() //construcao do tabuleiro
{
    string str = "";
    int num = 0;
    Offset offset;
    if(tamanho.getX() > 9){
        for (int x = -1 ; x < tamanho.getX(); x++) {
            if(x == -1){
                if(tamanho.getY() > 9) str.append(" ");
                str.append(" ");
            } else {
                str.append(to_string((x+1) / 10 %10));
            }
            str.append("|");
        }
        str.append("\n");
    }
    for (int x = -1 ; x < tamanho.getX(); x++) {
        if(x == -1){
            if(tamanho.getY() > 9) str.append(" ");
            str.append(" ");
        } else {
            str.append(to_string((x+1) %10));
        }
        str.append("|");
    }
    str.append("\n");
    if(tamanho.getX() > 9){
        str.append("-");
    }
    for (int x = -1 ; x < tamanho.getX(); x++) {
        str.append("--");
    }
    str.append("\n");
    for (int y = 0 ; y < tamanho.getY(); y++) {
        for (int x = -1 ; x < tamanho.getX(); x++) {
            if (x == -1) {
                if ((tamanho.getY() > 9) &&  ((y+1) < 10)){
                    str.append(" ");
                }
                str.append(to_string(y+1));
                str.append("|");
            }else{
                offset = Offset(x, y);
                if (abertos.naoContem(offset)) {
                    str.append("X|");
                } else {
                    num = dadoEm(offset);
                    if (num == LocalDeBomba) {
                        str.append("O|");
                    } else {
                        str.append(to_string(num));
                        str.append("|");
                    }
                }
            }
        }
        str.append("\n");
        if(tamanho.getX() > 9){
            str.append("-");
        }
        for (int x = -1 ; x < tamanho.getX(); x++) {
            str.append("--");
        }
        str.append("\n");
    }
    return str;
}

ostream& operator<<(ostream& os, Tabuleiro& tab) //operador
{
    os << "Tabuleiro:" << endl;
    os << tab.toString();
    return os;
}
