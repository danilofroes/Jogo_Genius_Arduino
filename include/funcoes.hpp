/*
Aqui são declaradas as variáveis e funções utilizadas no estrutura do código
*/

#include <Arduino.h>
#include "eletronica.hpp"

#pragma once

const int valorSequencia = 4;

// Variáveis de tempo
const int umSegundo = 1000;
const int meioSegundo = 500;

int sequenciaLuzes[valorSequencia];

/**
 * @brief Função para checar os botões
 * 
 * @return Se algum botão for apertado, o led do respectivo botão será acesso e retornará a porta do led, se nenhum for apertado, retornará -1
 */
int checarBotao() {

    if (digitalRead(BOTAO_AMARELO == LOW)) {
        return piscaLed(LED_AMARELO);
    }

    else if (digitalRead(BOTAO_AZUL == LOW)) {
        return piscaLed(LED_AZUL);
    }

    else if (digitalRead(BOTAO_VERDE == LOW)) {
        return piscaLed(LED_VERDE);
    }

    else if (digitalRead(BOTAO_VERMELHO == LOW)) {
        return piscaLed(LED_VERMELHO);
    }

    else {
        return -1;
    }

}

/**
 * @brief Gera um led de cor diferente aleatoriamente
 */
int corSortida() {

    return random(LED_VERDE, LED_AZUL + 1);

}

/**
 * @brief Função que vai definir a sequência de cores que irá piscar aleatoriamente
 */
void iniciaJogo() {

    int jogo = analogRead(0);

    randomSeed(jogo);

    for (int i = 0; i < valorSequencia; i++) {
        sequenciaLuzes[i] = corSortida();
    }

}

/**
 * @brief Função que faz um led acender e após 1 segundo apagar e aguarda meio segundo para o próximo passo
 * 
 * @param led Pino do led que será usado para piscar
 * 
 * @return Porta do led que piscou
 */
int piscaLed(int led) {

    digitalWrite(led, HIGH);
    delay(umSegundo);
    digitalWrite(led, LOW);
    delay(meioSegundo);

    return led;

}