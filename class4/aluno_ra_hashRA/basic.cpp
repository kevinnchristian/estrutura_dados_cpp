#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  // construtor aloca VETOR na região de memória
  length = 0;
  max_items = max;
  structure = new Aluno[max_items];   
}

Hash::~Hash(){ // destrutor desaloca VETOR na região de memória
  delete [] structure;
}

bool Hash::isFull() const { // verifica se o tamanho do vetor chegou no tamanho máximo
  return (length == max_items);
}

int Hash::getLength() const { // pega o tamanho do vetor
  return length;
}

void Hash::retrieveItem(Aluno& aluno, bool& found) {  // passando variáveis do tipo referência (&)
  int location = getHash(aluno);  // busca na estrutura de dados interna
  Aluno aux    = structure[location];  // atribui location caso haja na variável aluno
  if (aluno.getRa() != aux.getRa()) {  // se o getRa não existir
    found      = false; // aluno não existe/não_encontrado
  } else {
    found      = true;  // aluno existe/econtrado
    aluno      = aux;   // atribui oq pegamos aux neste aluno encontrado
  }
}

void Hash::insertItem(Aluno aluno) { // recebe um aluno por params para colocar dentro do meu vetor
  int location = getHash(aluno);  // faz um hash do RA
  structure[location] = aluno;    // diz posição e coloca aluno na posição 
  length++;  // incrementa o valor de elemento no vetor, aumenta um indice do vetor
}
void Hash::deleteItem(Aluno aluno) { // recebe aluno
  int location = getHash(aluno);  // pega o RA (faz o hash)
  structure[location] = Aluno();  // set construtor sem aluno (ra = -1, "")
  length--;  // decrementa o elemento, dimuni um indice do vetor
}

void Hash::print() {  // for para imprimir os elementos do vetor, incluindo o indice -1
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<<
      structure[i].getRa()<<", "<<
      structure[i].getNome()<<endl;
  }
}

// getHash() 
// Todo Aluno tem seu RA, vamos utilizar esse RA como indice do vetor
int Hash::getHash(Aluno aluno){ 
  return aluno.getRa() % max_items;  // pega o valor de RA e gera um valor entre 0 e 99
}                                    // para não estrapolar o valor max_items == 100
