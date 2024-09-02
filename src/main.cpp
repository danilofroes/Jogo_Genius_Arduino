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

   for (int i = 0; i < valorSequencia; i++) {

    piscaLed(sequenciaLuzes[i]);

   }

   int botaoApertado = checarBotao();

}  