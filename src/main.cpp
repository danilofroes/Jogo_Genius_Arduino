/*
Parte principal do código
*/

#include <Arduino.h>
#include "eletronica.hpp"
#include "funcoes.hpp"

void setup() {

  Serial.begin(9600);
  portas();
  iniciaJogo();

}

void loop() {

  switch (estadoAtual()) {

    case INICIO_PROXIMA_RODADA:
      rodada++;
      ledsRespondidos = 0;

      if (rodada <= SEQUENCIA) {
        iniciarSequenciaRodada();
      }

      break;

    case RESPOSTA_USUARIO:
      int resposta = checarBotao();

      if (resposta == -1) {
        return;
      }

      if (resposta == sequenciaLuzes[ledsRespondidos]) {
        ledsRespondidos++;
        Serial.println("Resposta certa");
      }

      else {
        Serial.println("Resposta errado");
      }

      rodada = SEQUENCIA + 2;

      break;

    case USUARIO_ACERTOU:
      ledsAcessos();
      break;
    
    case USUARIO_ERROU:
      ledsPiscando();
      break;
  }

  delay(MEIO_SEGUNDO);

}  