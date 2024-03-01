#ifndef MENU_H
#define MENU_H

#pragma once

enum Opcoes {
    ADICAO = 1,
    //SUBTRACAO,
    //MULTIPLICACAO,
    //DIVISAO,
    //CONJUGADO,
    //EXPONENCIACAO,
    //MODULO,
    SAIR = 8,    
};

void Menu();
void Adicao();
void Modulo();
void Divisao();
void Subtracao();
void Conjugado();
void Multiplicacao();
void Exponenciacao();
void ValidarOpcao(int&);

#endif