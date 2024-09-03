/*
Aqui são declaradas as variáveis e funções utilizadas no estrutura do código
*/

#include <Arduino.h>
#include "eletronica.hpp"

#pragma once

// Variáveis de tempo
const int umSegundo = 1000;
const int meioSegundo = 500;

const int valorSequencia = 4;
int sequenciaLuzes[valorSequencia];
int rodada = 0;
int ledsRespondidos = 0;

enum Estados {
    INICIO_PROXIMA_RODADA,
    RESPOSTA_USUARIO,
    USUARIO_ACERTOU,
    USUARIO_ERROU
};

/**
 * @brief Função para ver em qual estado o jogo está
 * 
 * @return Retorna o estado atual do jogo
 */
int estadoAtual() {

    if (rodada <= valorSequencia) {

        if (ledsRespondidos == rodada) {
            return INICIO_PROXIMA_RODADA;
        }

        else {
            return RESPOSTA_USUARIO;
        }
    }

    else if (rodada == valorSequencia + 1) {
        return USUARIO_ACERTOU;
    }

    else {
        return USUARIO_ERROU;
    }

}

/**
 * @brief Função que vai definir a sequência de cores que irá piscar aleatoriamente
 */
void iniciaJogo() {

    int jogo = analogRead(0);
    randomSeed(jogo);

    int corAleatoria = random(LED_VERDE, LED_AZUL + 1);

    for (int i = 0; i < valorSequencia; i++) {
        sequenciaLuzes[i] = corAleatoria;
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

/**
 * @brief Função que ficará responsável por iniciar cada rodada
 */
void iniciarSequenciaRodada() {

    for (int i = 0; i < rodada; i++) {

    piscaLed(sequenciaLuzes[i]);

   }
}

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

void ledsAcessos() {

    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AZUL, HIGH);

    delay(umSegundo);

    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AZUL, LOW);

    delay(meioSegundo);

}

void ledsPiscando() {

    piscaLed(LED_AMARELO);
    piscaLed(LED_VERDE);
    piscaLed(LED_VERMELHO);
    piscaLed(LED_AZUL);
    delay(meioSegundo);

}