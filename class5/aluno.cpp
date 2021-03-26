#include "aluno.h"

Aluno::Aluno(){ // construtor vazio da class Aluno
  this->ra   = -1;  // indica que não tem o aluno procurado
  this->nome = "";
};  
Aluno::Aluno(int ra, std::string nome){ // construtor com params da class Aluno
  this->ra    = ra;  // atribui o params para o atributo
  this->nome  = nome;
}
string Aluno::getNome() const {  // retorna nome do aluno do nosso atributo
  return nome;
}
int Aluno::getRa() const{  // retorna (RA) do nosso atributo
  return ra;
}
