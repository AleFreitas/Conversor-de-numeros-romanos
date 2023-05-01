// "Copyright 2023 <AleFreitas>" [legal/copyright] [5]
#include "./romanos.hpp"
#include <iostream>
#include <string>

#define kNumeroRomano_I 1
#define kNumeroRomano_V 5
#define kNumeroRomano_X 10
#define kNumeroRomano_L 50
#define kNumeroRomano_C 100
#define kNumeroRomano_D 500
#define kNumeroRomano_M 1000

int LetraValida(char letra) {
  if (letra == 'I' || letra == 'V' || letra == 'X' ||
    letra == 'L' || letra == 'C' || letra == 'D' ||
    letra == 'M') return 1;
  return 0;
}

int StringValida(std::string numero) {
  for (int i = 0; i < numero.length(); i++) {
    if (!LetraValida(numero[i])) {
      return 0;
    }
  }
  return 1;
}

// recebe 4 argumentos, um numero indo-arabico e um determinado comparador
// equivalente ao valor de um numero romano, as repetições que o numero
// indo-arabico possui e as repetições permitidas no caso do comparador.
// retorna 1 se encontrar repetições indevidas.
int ComparaNumeroRepeticao(int numero, int comparador_numero,
int reps, int comparador_reps) {
    if (numero == comparador_numero) {
        if (reps >= comparador_reps) return 1;
    }
    return 0;
}

// recebe um numero indo-arabico e a sua quantidade de repetições na string de
// origem verifica se esse numero possui mais repetições do que é permitido no
// sistema de numeros romanos e caso não possua repetições indevidas ele
// retorna 0.
int VerificaRepeticaoIndevida(int numero, int reps) {
    int duas_repeticoes = 2;
    int quatro_repeticoes = 4;
    if (ComparaNumeroRepeticao(numero, kNumeroRomano_I,
    reps, quatro_repeticoes)) return 1;
    if (ComparaNumeroRepeticao(numero, kNumeroRomano_V,
    reps, duas_repeticoes)) return 1;
    if (ComparaNumeroRepeticao(numero, kNumeroRomano_X,
    reps, quatro_repeticoes)) return 1;
    if (ComparaNumeroRepeticao(numero, kNumeroRomano_L,
    reps, duas_repeticoes)) return 1;
    if (ComparaNumeroRepeticao(numero, kNumeroRomano_C,
    reps, quatro_repeticoes)) return 1;
    if (ComparaNumeroRepeticao(numero, kNumeroRomano_D,
    reps, duas_repeticoes)) return 1;
    if (ComparaNumeroRepeticao(numero, kNumeroRomano_M,
    reps, quatro_repeticoes)) return 1;
    return 0;
}

int EncontraRepeticoes(std::string numero) {
    int rep_numero_anterior = 0;
    int numero_anterior = 0;
    for (int i = 0; i < numero.length(); i++) {
        if (numero[i] == 'I') {
            if (numero_anterior != kNumeroRomano_I) {
                numero_anterior = kNumeroRomano_I;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'V') {
            if (numero_anterior != kNumeroRomano_V) {
                numero_anterior = kNumeroRomano_V;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'X') {
            if (numero_anterior != kNumeroRomano_X) {
                numero_anterior = kNumeroRomano_X;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'L') {
            if (numero_anterior != kNumeroRomano_L) {
                numero_anterior = kNumeroRomano_L;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'C') {
            if (numero_anterior != kNumeroRomano_C) {
                numero_anterior = kNumeroRomano_C;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'D') {
            if (numero_anterior != kNumeroRomano_D) {
                numero_anterior = kNumeroRomano_D;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (numero[i] == 'M') {
            if (numero_anterior != kNumeroRomano_M) {
                numero_anterior = kNumeroRomano_M;
                rep_numero_anterior = 0;
            }
            rep_numero_anterior++;
        }
        if (VerificaRepeticaoIndevida(numero_anterior,
        rep_numero_anterior)) return 1;
    }
    return 0;
}

int DescobreUnidadeEmRomano(char letra) {
    if (letra == 'I') return kNumeroRomano_I;
    if (letra == 'V') return kNumeroRomano_V;
    if (letra == 'X') return kNumeroRomano_X;
    if (letra == 'L') return kNumeroRomano_L;
    if (letra == 'C') return kNumeroRomano_C;
    if (letra == 'D') return kNumeroRomano_D;
    if (letra == 'M') return kNumeroRomano_M;
    return 0;
}

int ConverteNumero(std::string numero) {
    int resultado = 0;
    int numero_anterior = DescobreUnidadeEmRomano(numero[0]);
    for (int i = 1; i < numero.length(); i++) {
        int numero_atual = DescobreUnidadeEmRomano(numero[i]);
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
    int ultimo_numero = DescobreUnidadeEmRomano(numero[numero.length()-1]);
    resultado+=ultimo_numero;
    return resultado;
}

// recebe uma string com numeros romanos validos e garante que sua
// conversão não corresponde a um numero base do sistema romano.
// retorna o resultado desta conversão quando a verificação ocorrer
// com sucesso.
int GaranteResultadoValido(std::string numero) {
    int resultado = ConverteNumero(numero);
    if (numero.length() >= 2 &&
    (resultado == kNumeroRomano_I || resultado == kNumeroRomano_V ||
    resultado == kNumeroRomano_X || resultado == kNumeroRomano_L ||
    resultado == kNumeroRomano_C || resultado == kNumeroRomano_D ||
    resultado == kNumeroRomano_M)) return 0;
    return resultado;
}

int RomanosParaDecimal(char const * num_romano) {
  if (!StringValida(num_romano)) return -1;
  if (EncontraRepeticoes(num_romano)) return -1;
  int resultado = GaranteResultadoValido(num_romano);
  if (!resultado) return -1;
  return resultado;
}
