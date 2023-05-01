#include "romanos.hpp"
#include <iostream>
#include <string>

#define numero_romano_I 1
#define numero_romano_V 5
#define numero_romano_X 10
#define numero_romano_L 50
#define numero_romano_C 100
#define numero_romano_D 500
#define numero_romano_M 1000

using namespace std;

int letra_valida(char letra) {
  if (letra == 'I' || letra == 'V' || letra == 'X' ||
    letra == 'L' || letra == 'C' || letra == 'D' ||
    letra == 'M') return 1;
  return 0;
}

int string_valida(string numero) {
  for (int i = 0; i < numero.length(); i++) {
    if (!letra_valida(numero[i])) {
      return 0;
    }
  }
  return 1;
}

int compara_numero_repeticao (int numero, int comparador_numero, int reps, int comparador_reps) {
    if (numero == comparador_numero) {
        if (reps >= comparador_reps) return 1;
    }
    return 0;
}

int verifica_repeticao_indevida (int numero, int reps) {
    int duas_repeticoes = 2;
    int quatro_repeticoes = 4;
    if(compara_numero_repeticao(numero, numero_romano_I, reps, quatro_repeticoes)) return 1;
    if(compara_numero_repeticao(numero, numero_romano_V, reps, duas_repeticoes)) return 1;
    if(compara_numero_repeticao(numero, numero_romano_X, reps, quatro_repeticoes)) return 1;
    if(compara_numero_repeticao(numero, numero_romano_L, reps, duas_repeticoes)) return 1;
    if(compara_numero_repeticao(numero, numero_romano_C, reps, quatro_repeticoes)) return 1;
    if(compara_numero_repeticao(numero, numero_romano_D, reps, duas_repeticoes)) return 1;
    if(compara_numero_repeticao(numero, numero_romano_M, reps, quatro_repeticoes)) return 1;
    return 0;
}

int encontra_repeticoes (string numero){
    int rep_numero_anterior = 0;
    int numero_anterior = 0;
    for (int i = 0; i < numero.length(); i++) {
        if(numero[i] == 'I') {
            if(numero_anterior != 1) {
                numero_anterior = 1;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        };
        if(numero[i] == 'V') {
            if(numero_anterior != 5) {
                numero_anterior = 5;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        };
        if(numero[i] == 'X') {
            if(numero_anterior != 10) {
                numero_anterior = 10;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        };
        if(numero[i] == 'L') {
            if(numero_anterior != 50) {
                numero_anterior = 50;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        };
        if(numero[i] == 'C') {
            if(numero_anterior != 100) {
                numero_anterior = 100;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        };
        if(numero[i] == 'D') {
            if(numero_anterior != 500) {
                numero_anterior = 500;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        };
        if(numero[i] == 'M') {
            if(numero_anterior != 1000) {
                numero_anterior = 1000;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        };
        if(verifica_repeticao_indevida(numero_anterior, rep_numero_anterior)) return 1;
    }
    return 0;
}

int romanos_para_decimal(char const * num_romano)
{
  if (!string_valida(num_romano)) return -1;
  if (encontra_repeticoes(num_romano)) return -1;
  return 0; 
}
