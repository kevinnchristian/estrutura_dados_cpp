// Tipo abstrato de dados
#include "aluno.h"

class Hash {
 public:
  Hash(int max_items = 100); // construtor dizendo que num. máximo de lemento é igual 100
  ~Hash();  // destrutor
  bool isFull() const;   // método para saber se preenchi os 100 elementos
  int getLength() const; // método para saber quantos elementos realmente estão nessa estrutura
  
  void retrieveItem(Aluno& aluno, bool& found); // método  
  void insertItem(Aluno aluno);  // método  
  void deleteItem(Aluno aluno);  // método  
  void print();
 private:
  int getHash(Aluno aluno);  // método pega de dentro do Aluno seu RA 
  int   max_items;   // número máximo de elementos
  int   length;      // quantos elementos realmente tem na minha estrutura
  Aluno* structure;  // ponteiro para minha estrutura Vetor, que representa o Aluno
};