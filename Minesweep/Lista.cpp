#include "Lista.hpp" //lista eh um generico

template <typename T>
Lista<T>::Lista()//criando um construtor que inicializa lista com tamanho 0 e
{                //lista igual a um novo vetor de tamanho que comeca em 0
    tamanho = 0;
    lista = new T[0];
}

template <typename T>
Lista<T>::Lista(T* lista, int tamanho)
{
    this->tamanho = tamanho; //define tamanho
    this->lista = new T[tamanho]; //define que o vetor vai receber o valor de
                                  //tamanho para fazer um novo tamanho
    for (int i = 0; i < tamanho; i++) //percorrendo todos os numeros de i menores que tamanho e adicionando um
    {                                 //esse i é sempre colocado dentro do vetor de listas
        this->lista[i] = lista[i]; 
    }
}

template <typename T>
Lista<T>::~Lista() //destrutor de listas
{
    delete[] lista;
}

template <typename T>
int Lista<T>::getTamanho() { //pegando o tamanho e retornando ele mesmo
    return tamanho;
}

template <typename T>
void Lista<T>::adicionar(T objeto)
{
    tamanho++; //adiciona um ao tamanho
    T* novaLista = new T[tamanho]; //esse novo tamanho eh definido aqui como um novo T que
                                   //eh igual ao nova lista
    for (int i = 0; i < tamanho - 1; i++) //percorre todo o tamanho menos um e coloca no vetor de lista
    {
        novaLista[i] = lista[i];
    }
    novaLista[tamanho - 1] = objeto; //cria a nova lista com tamanho menos 1 e iguala ela ao objeto
    delete[] lista; //deleta a lista "antiga"
    lista = novaLista; //diz que a lista "antiga" eh igual a nova
}

template <typename T>
void Lista<T>::remover(int indice) //mesma funcao do adiciona, porem remove
{
    tamanho--;
    T* novaLista = new T[tamanho];
    for (int i = 0; i < indice; i++)
    {
        novaLista[i] = lista[i];
    }
    for (int i = indice; i < tamanho; i++)
    {
        novaLista[i] = lista[i + 1];
    }
    delete[] lista;
    lista = novaLista;
}

template <typename T>
void Lista<T>::inserir(int indice, T objeto) 
{
    tamanho++;
    T* novaLista = new T[tamanho];
    for (int i = 0; i < indice; i++)
    {
        novaLista[i] = lista[i];
    }
    novaLista[indice] = objeto;
    for (int i = indice + 1; i < tamanho; i++)
    {
        novaLista[i] = lista[i - 1];
    }
    delete[] lista;
    lista = novaLista;
}

template <typename T>
void Lista<T>::limpar()
{
    tamanho = 0;
    delete[] lista;
    lista = new T[0];
}

template <typename T>
bool Lista<T>::contem(T objeto)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == objeto) return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::naoContem(T objeto)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == objeto) return false;
    }
    return true;
}

template <typename T>
bool Lista<T>::estaVazia()
{
    return tamanho == 0;
}

template <typename T>
bool Lista<T>::naoEstaVazia()
{
    return tamanho != 0;
}

template <typename T>
T* Lista<T>::operator [](int indice)
{
    return &lista[indice];
}

template <typename T>
T* const Lista<T>::operator [](int indice) const
{
    return &lista[indice];
}

template <typename T>
Lista<T> Lista<T>::operator +(Lista<T> lista)
{
    Lista<T> novaLista;
    for (int i = 0; i < tamanho; i++)
    {
        novaLista.adicionar(this->lista[i]);
    }
    for (int i = 0; i < lista.tamanho; i++)
    {
        novaLista.adicionar(lista.lista[i]);
    }
    return novaLista;
}

template <typename T>
bool Lista<T>::operator ==(Lista<T> lista)
{
    if (tamanho != lista.tamanho) return false;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return false;
    }
    return true;
}

template <typename T>
template <typename U>
bool Lista<T>::operator ==(Lista<U> lista)
{
    if (tamanho != lista.tamanho) return false;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return false;
    }
    return true;
}

template <typename T>
template <typename U>
bool Lista<T>::operator !=(Lista<U> lista)
{
    if (tamanho != lista.tamanho) return true;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::operator !=(Lista<T> lista)
{
    if (tamanho != lista.tamanho) return true;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return true;
    }
    return false;
}
