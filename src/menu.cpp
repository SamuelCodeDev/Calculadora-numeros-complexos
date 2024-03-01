#include <iostream>
#include <cstdlib>
#include <limits>
#include "complexo.hpp"
#include "menu.h"
using std::cin;
using std::cout;
using std::streamsize;
using std::stringstream;
using std::numeric_limits;

inline void LimparTela() {
#if defined(WIN32)
    system("cls");
#else
    system("clear");
#endif
}

inline void AguardarPressionarEnter() {
    cout << "Pressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    LimparTela();
}

void ValidarOpcao(int & opcao) {
    while(opcao < 1 && opcao > 8 && cin.fail()) {
        cout << "Digite novamente sua opcao: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> opcao;
    }
}

void LerComplexos(Complexo & a, Complexo & b) {
    cout << "\nDigite o numero complexo (a+bi): ";
    cin >> a;
    cout << "Digite outro numero complexo (a+bi): ";
    cin >> b;
}

void Menu() {
    cout << "================================================\n";
    cout << "\tCalculadora de numeros complexos\n";
    cout << "================================================\n\n";
    cout << "1) Adicao\n";
    cout << "2) Subtracao\n";
    cout << "3) Multiplicacao\n";
    cout << "4) Divisao\n";
    cout << "5) Conjugado\n";
    cout << "6) Exponenciacao\n";
    cout << "7) Modulo\n";
    cout << "8) Sair\n\n";
    cout << "Digite sua opcao: ";
}

void Adicao() {
    Complexo a, b;
    LerComplexos(a,b);
    cout << "Resultado: " << a + b << '\n';
    AguardarPressionarEnter();
}

void Subtracao() {
    Complexo a, b;
    LerComplexos(a,b);
    cout << "Resultado: " << a - b << '\n';
    AguardarPressionarEnter();
}

void Multiplicacao() {
    Complexo a, b;
    LerComplexos(a,b);
    cout << "Resultado: " << a * b << '\n';
    AguardarPressionarEnter();
}

void Divisao() {
    Complexo a, b;
    LerComplexos(a,b);
    cout << "Resultado: " << a / b << '\n';
    AguardarPressionarEnter();
}

void Conjugado() {
    cout << "\nDigite o numero complexo (a+bi): ";
    Complexo a;
    cin >> a;
    cout << "Resultado: " << a.Conjugado() << '\n';
    AguardarPressionarEnter();
}

void Exponenciacao() {
    cout << "\nDigite o numero complexo (a+bi): ";
    Complexo a;
    cin >> a;
    
    cout << "Digite o valor expoente: ";
    int expoente;
    cin >> expoente;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite novamente o valor expoente: ";
        cin >> expoente;
    }

    cin.ignore();
    cout << "Resultado: " << a.Exponenciacao(expoente) << '\n';
    AguardarPressionarEnter();
}

void Modulo() {
    cout << "\nDigite o numero complexo (a+bi): ";
    Complexo a;
    cin >> a;
    cout << "Resultado: " << a.Modulo() << '\n';
    AguardarPressionarEnter();
}