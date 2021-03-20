#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Aluno[max_items];
}

Hash::~Hash(){
  delete [] structure;
}

bool Hash::isFull() const {
  return (length == max_items);
}

int Hash::getLength() const {
  return length;
}

// retriveItem(), insertItem() e deleteItem() foram alterados para seguir a finalidade 
// da função hash
// chave -1 vazio, -2 disponível
// insert trata -1 e -2 como eu tenho que inserir
// retrive trata [-1 como tenho que parar minha busca pq está vazio] e [-2 como está disponível]

void Hash::retrieveItem(Aluno& aluno, bool& found) { // passa aluno e o boolean referênciando
  int startLoc = getHash(aluno);  // busca hash (RA)
  bool moreToSearch = true;  // se for preciso buscar mais ele passa por essa variável
  int location = startLoc;   // iterar inciando em startLoc, posição base em que se espera que a chave esteja
  do {
    if (structure[location].getRa() == aluno.getRa() ||
	structure[location].getRa() == -1)  // procurando se der false ele para de procurar
      moreToSearch = false;
    else  // se não continue procurando, + 1 é pq se chegar no fim do vetor e não achar, ele volta para incio e continua a procurar
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);
  
  found = (structure[location].getRa() == aluno.getRa() );  // verificar se encontrou, ele sai do while quando o elemento 
  if (found) {                                              // é igual o RA do aluno
    aluno = structure[location];
  }
}

void Hash::insertItem(Aluno aluno) {
  int location;
  location = getHash(aluno);
  while (structure[location].getRa() > 0) // RA > 0 significa ocupado, se for -1 (vazio) ou -2 (disponível) ele pode inserir
    location = (location + 1) % max_items;
  structure[location] = aluno;
  length++;
}

void Hash::deleteItem(Aluno aluno) {   // procure o elemento, mesmo critério do retrive 
  int startLoc = getHash(aluno);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getRa() == aluno.getRa() ||
	structure[location].getRa() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  if (structure[location].getRa() == aluno.getRa()) {  // só muda aqui
    structure[location] = Aluno(-2,"");  // em uma proxima busca eu tenho que continua a busca
    length--;                            // pq no delete agora ele coloca -2 disponível
  }
}

void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getRa()<<", "<<structure[i].getNome()<<endl;
  }
}

int Hash::getHash(Aluno aluno){
  return aluno.getRa() % max_items;
}

