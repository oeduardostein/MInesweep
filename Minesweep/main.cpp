#include "Tabuleiro.hpp"

using namespace std;

int main()
{
    int menu(string texto, int min, int max);

    int opcao = 0;
    int x = 0;
    int y = 0;
    Tamanho tamanho = Tamanho(12, 12);
    Tabuleiro tabuleiro = Tabuleiro(tamanho, 1);

    while (1) {
        cout << tabuleiro;
        cout << endl;

        opcao = menu("Menu:\n1.Sair\n2.Digitar coordenada\n3.Novo jogo", 1, 3);
        if (opcao == 1) break;
        else if (opcao == 2) {
            x = menu("\nDigite a posicao horixontal(x):", 1, tamanho.getX());
            y = menu("\nDigite a posicao vertical(y):", 1, tamanho.getY());
        } else if (opcao == 3) {
            tamanho = Tamanho(5, 7);
            tabuleiro.novoJogo(tamanho, 2);
        }
    }
    
    return 0;
}

int menu(string texto, int min, int max) { // apenas um menu de opcoes para o usuario dizer o que quer fazer
    int opcao;
    cout << texto;
    do{
        cin >> opcao;
        if(opcao < min || opcao > max) {
            cout << "Opcao invalida! Tente noamente: ";
        }
    }while(opcao < min || opcao > max);
    return opcao;
}
