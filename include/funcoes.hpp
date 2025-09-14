/*
Aqui são declaradas as variáveis e funções utilizadas no estrutura do código
*/

#include <Arduino.h>
#include "eletronica.hpp"

#pragma once

// Variáveis de tempo
#define UM_SEGUNDO       1000
#define MEIO_SEGUNDO     500

#define SEQUENCIA        4

uint8_t sequenciaLuzes[SEQUENCIA];
uint8_t rodada = 0;
uint8_t ledsRespondidos = 0;

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
uint8_t estadoAtual() {

    if (rodada <= SEQUENCIA) {

        if (ledsRespondidos == rodada) {
            return INICIO_PROXIMA_RODADA;
        }

        else {
            return RESPOSTA_USUARIO;
        }
    }

    else if (rodada == SEQUENCIA + 1) {
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

    for (uint8_t i = 0; i < SEQUENCIA; i++) {
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
uint8_t piscaLed(uint8_t led) {

    digitalWrite(led, HIGH);
    delay(UM_SEGUNDO);
    digitalWrite(led, LOW);
    delay(MEIO_SEGUNDO);

    return led;
}

/**
 * @brief Função que ficará responsável por iniciar cada rodada
 */
void iniciarSequenciaRodada() {

    for (uint8_t i = 0; i < rodada; i++) {

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

    delay(UM_SEGUNDO);

    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AZUL, LOW);

    delay(MEIO_SEGUNDO);

}

void ledsPiscando() {

    piscaLed(LED_AMARELO);
    piscaLed(LED_VERDE);
    piscaLed(LED_VERMELHO);
    piscaLed(LED_AZUL);
    delay(MEIO_SEGUNDO);

}