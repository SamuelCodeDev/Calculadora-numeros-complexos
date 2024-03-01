#include <iostream>
#include "menu.h"
using std::cin;
using std::cout;

int main() {
    void (*pf[8])(void) {
        nullptr,
        Adicao,
        Subtracao,
        Multiplicacao,
        Divisao,
        Conjugado,
        Exponenciacao,
        Modulo
    };

    Menu();
    int opcao;
    cin >> opcao;
    ValidarOpcao(opcao);

    while(opcao != SAIR) {
        pf[opcao]();
        Menu();
        cin >> opcao;
        ValidarOpcao(opcao);
    }

    return 0;
}