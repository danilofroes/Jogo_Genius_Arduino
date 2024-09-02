/*
Aqui é declarado toda parte eletrônica do jogo
*/

#include <Arduino.h>
#pragma once

// Pinagem
#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 5

#define BOTAO_VERDE 10
#define BOTAO_AMARELO 11
#define BOTAO_VERMELHO 12
#define BOTAO_AZUL 13

void portas() {

    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_AZUL, OUTPUT);

    pinMode(BOTAO_VERDE, INPUT_PULLUP);
    pinMode(BOTAO_AMARELO, INPUT_PULLUP);
    pinMode(BOTAO_VERMELHO, INPUT_PULLUP);
    pinMode(BOTAO_AZUL, INPUT_PULLUP);

}