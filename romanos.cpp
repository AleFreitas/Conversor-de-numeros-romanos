#include "romanos.hpp"
#include <iostream>
#include <string>


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


int romanos_para_decimal(char const * num_romano)
{
  if (!string_valida(num_romano)) return -1;
  return 0; 
}
