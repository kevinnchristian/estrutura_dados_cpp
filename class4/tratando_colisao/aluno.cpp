#include "aluno.h"

Aluno::Aluno() {     // construtor da class Aluno
  this -> ra = -1;   // posição está vazia
  this -> nome = ""; // nome vazio
};

Aluno::Aluno(int ra, std::string nome) {  // construtor que recebe params
  this -> ra = ra;      // meu atributo recebe params do construtor
  this -> nome = nome;  // meu atributo recebe params do construtor
}

string Aluno::getNome() const {
  return nome;
}

int Aluno::getRa() const {
  return ra;
}