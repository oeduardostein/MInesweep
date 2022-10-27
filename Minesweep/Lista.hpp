#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include "Bomba.hpp"

template <typename T>
class Lista
{
    public:
        Lista();
        Lista(T* lista, int tamanho);
        ~Lista();
        int getTamanho();
        void adicionar(T objeto);
        void remover(int indice);
        void inserir(int indice, T objeto);
        void limpar();
        bool contem(T objeto);
        bool naoContem(T objeto);
        bool estaVazia();
        bool naoEstaVazia();
        T* operator [](int indice);
        T* const operator [](int indice) const;
        Lista<T> operator +(Lista<T> lista);
        bool operator ==(Lista<T> lista);
        template <typename U>
        bool operator ==(Lista<U> lista);
        bool operator !=(Lista<T> lista);
        template <typename U>
        bool operator !=(Lista<U> lista);
    protected:
        int tamanho;
        T* lista;

};

#endif // LISTA_HPP_INCLUDED
