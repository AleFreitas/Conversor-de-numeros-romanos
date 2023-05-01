// "Copyright 2023 <AleFreitas>" [legal/copyright] [5]
#include "./romanos.hpp"
#include <iostream>
#include <string>

#define numero_romano_I 1
#define numero_romano_V 5
#define numero_romano_X 10
#define numero_romano_L 50
#define numero_romano_C 100
#define numero_romano_D 500
#define numero_romano_M 1000

int letra_valida(char letra) {
  if (letra == 'I' || letra == 'V' || letra == 'X' ||
    letra == 'L' || letra == 'C' || letra == 'D' ||
    letra == 'M') return 1;
  return 0;
}

int string_valida(std::string numero) {
  for (int i = 0; i < numero.length(); i++) {
    if (!letra_valida(numero[i])) {
      return 0;
    }
  }
  return 1;
}

int compara_numero_repeticao(int numero, int comparador_numero,
int reps, int comparador_reps) {
    if (numero == comparador_numero) {
        if (reps >= comparador_reps) return 1;
    }
    return 0;
}

int verifica_repeticao_indevida(int numero, int reps) {
    int duas_repeticoes = 2;
    int quatro_repeticoes = 4;
    if (compara_numero_repeticao(numero, numero_romano_I,
    reps, quatro_repeticoes)) return 1;
    if (compara_numero_repeticao(numero, numero_romano_V,
    reps, duas_repeticoes)) return 1;
    if (compara_numero_repeticao(numero, numero_romano_X,
    reps, quatro_repeticoes)) return 1;
    if (compara_numero_repeticao(numero, numero_romano_L,
    reps, duas_repeticoes)) return 1;
    if (compara_numero_repeticao(numero, numero_romano_C,
    reps, quatro_repeticoes)) return 1;
    if (compara_numero_repeticao(numero, numero_romano_D,
    reps, duas_repeticoes)) return 1;
    if (compara_numero_repeticao(numero, numero_romano_M,
    reps, quatro_repeticoes)) return 1;
    return 0;
}

int encontra_repeticoes(std::string numero) {
    int rep_numero_anterior = 0;
    int numero_anterior = 0;
    for (int i = 0; i < numero.length(); i++) {
        if (numero[i] == 'I') {
            if (numero_anterior != numero_romano_I) {
                numero_anterior = numero_romano_I;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'V') {
            if (numero_anterior != numero_romano_V) {
                numero_anterior = numero_romano_V;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'X') {
            if (numero_anterior != numero_romano_X) {
                numero_anterior = numero_romano_X;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'L') {
            if (numero_anterior != numero_romano_L) {
                numero_anterior = numero_romano_L;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'C') {
            if (numero_anterior != numero_romano_C) {
                numero_anterior = numero_romano_C;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'D') {
            if (numero_anterior != numero_romano_D) {
                numero_anterior = numero_romano_D;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'M') {
            if (numero_anterior != numero_romano_M) {
                numero_anterior = numero_romano_M;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (verifica_repeticao_indevida(numero_anterior,
        rep_numero_anterior)) return 1;
    }
    return 0;
}

int descobre_unidade_em_romano(char letra) {
    if (letra == 'I') return numero_romano_I;
    if (letra == 'V') return numero_romano_V;
    if (letra == 'X') return numero_romano_X;
    if (letra == 'L') return numero_romano_L;
    if (letra == 'C') return numero_romano_C;
    if (letra == 'D') return numero_romano_D;
    if (letra == 'M') return numero_romano_M;
    return 0;
}

int converte_numero(std::string numero) {
    int resultado = 0;
    int numero_anterior = descobre_unidade_em_romano(numero[0]);
    for (int i = 1; i < numero.length(); i++) {
        int numero_atual = descobre_unidade_em_romano(numero[i]);
        if (numero_atual > numero_anterior) {
            // subtrativo
            resultado -= numero_anterior;
            numero_anterior = numero_atual;
        } else if (numero_atual <= numero_anterior) {
            // aditivo
            resultado += numero_anterior;
            numero_anterior = numero_atual;
        }
    }
    int ultimo_numero = descobre_unidade_em_romano(numero[numero.length()-1]);
    resultado+=ultimo_numero;
    return resultado;
}

int garante_resultado_valido(std::string numero) {
    int resultado = converte_numero(numero);
    if (numero.length() >= 2 &&
    (resultado == numero_romano_I || resultado == numero_romano_V ||
    resultado == numero_romano_X || resultado == numero_romano_L ||
    resultado == numero_romano_C || resultado == numero_romano_D ||
    resultado == numero_romano_M)) return 0;
    return resultado;
}

int romanos_para_decimal(char const * num_romano) {
  if (!string_valida(num_romano)) return -1;
  if (encontra_repeticoes(num_romano)) return -1;
  int resultado = garante_resultado_valido(num_romano);
  if (!resultado) return -1;
  return resultado;
}
