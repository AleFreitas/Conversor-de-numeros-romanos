# Conversor-de-numeros-romanos
Este projeto é um conversor de numeros romanos (I,V,X) para indo-arábicos (1,2,3) feito com o objetivo<br>
de estudar programação orientada a testes na linguagem c++.<br>
Neste projeto fiz uso de boas práticas de estilo e padronização de código com o auxilio de ferramentas<br>
populares como cppcheck, cpplint e etc.<br><br>
Este projeto tem sua função main gerada pela ferramenta <a href="https://github.com/catchorg/Catch2">Catch2</a>
## Preparando o ambiente

Para que este projeto funcione é necessário ter um compilador de c++ como\
o g++ instalado em sua máquina!\
Clone este repositório utilizando o seguinte comando em seu terminal:
```
  git clone https://github.com/AleFreitas/Conversor-de-numeros-romanos
```
Atualize seus pacotes:
```
sudo apt-get update
```
Para rodar os testes apropriadamente neste projeto é necessário baixar as seguintes ferramentas:\
<strong>Caso você não utilize uma distribuição linux debian procure o comando\
adequado na pagina oficial de cada ferramenta<strong>
  - verificador estático: cppcheck   
  ``` 
  sudo apt-get install cppcheck
  ```
  - verificador de estilo: cpplint   
  ```
  pip install cpplint
  ```
  - verificador dinâmico: valgrind   
  ```
  sudo apt-get install valgrind
  ```
  - verificador de cobertura: gcov
  ```
  sudo apt-get install gcovr
  ```
## Como rodar o projeto
O arquivo <a href="https://github.com/AleFreitas/Conversor-de-numeros-romanos/blob/master/Makefile">makefile</a> deste repositório contem as regras de\
compilação e de testes necessários para rodar o projeto.
### Comandos
Rode estes comandos no seu terminal
  - compilar o projeto e exibir os resultados dos testes de codigo
  ```
  make
  ```
  - compilar o projeto
  ```
  make compile
  ```
  - compilar o projeto e checar a cobertura dos testes sobre o código
  ```
  make gcov
  ```
  - compilar e exibir a checagem estática no código
  ```
  make cppcheck
  ```
  - compilar o projeto e exibir o resultado dos testes de código
  ```
  make test
  ```
  - compilar o projeto e exibir o resultado dos testes de estilo do código
  ```
  make cpplint
  ```
  - compilar o projeto e exibir a checagem dinamica no código
  ```
  make valgrind
  ```
