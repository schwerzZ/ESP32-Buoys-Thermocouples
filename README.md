# Projeto ESP32 - Acionamento de Boias e Leitura de Termopares

Este projeto utiliza o ESP32 para monitorar o status de quatro boias e ler a temperatura de dois termopares (MAX6675). 
O objetivo é desenvolver um sistema de controle de nível de líquidos utilizando sensores de temperatura.

## Componentes
- ESP32
- 4 Boias de nível
- 2 Termopares MAX6675

## Diagrama de Conexões
![Diagrama de Conexões](boia.jpg)

## Código
O código está no arquivo `main.cpp` e utiliza a biblioteca MAX6675 para leitura dos termopares.

## Como Funciona
O código lê o estado das boias e a temperatura dos termopares a cada segundo (intervalo ajustável) utilizando a função `millis()` para controlar o tempo de leitura, evitando o uso de `delay()`.

## Bibliotecas Necessárias
- [Adafruit Sensor](https://github.com/adafruit/Adafruit_Sensor)
- [MAX6675](https://github.com/adafruit/MAX6675-library)
