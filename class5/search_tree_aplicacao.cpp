#include "search_tree.h"
using namespace std;

const int NUM_ALUNOS = 8;

int main() {
  SearchTree searchTree;

  int ras[NUM_ALUNOS] = {20, 18, 58, 7, 19, 26, 25, 30}; // RA's dos alunos    
  string nomes[NUM_ALUNOS] = { // nome dos aluno
    "Pedro", "Raul", "Paulo",
    "Carlos", "Lucas", "Maria",
    "Samanta", "ulisses"};
  Aluno alunos[NUM_ALUNOS];

  for (int i = 0; i < NUM_ALUNOS; i++){ // insira o nome dos aluno, de acordo a ordem do RA do aluno
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunos[i] = aluno;
    searchTree.insertAluno(aluno);
  }

  // Lembra de usar a imagem da árvore da Aula 3, semana 5
  // Imprima seguindo as regras de percursos
  cout << "Pre:  ";
  searchTree.printPreOrder();
  cout << endl;
  cout << "In:   ";
  searchTree.printInOrder();
  cout << endl;
  cout << "Post: ";
  searchTree.printPostOrder();
  cout << endl;

  // Removendo aluno na raiz;
  searchTree.deleteAluno(alunos[0].getRa());
  cout << "********" << endl;
  cout << "Pre:  ";
  searchTree.printPreOrder();
  cout << endl;
  cout << "In:   ";
  searchTree.printInOrder();
  cout << endl;
  cout << "Post: ";
  searchTree.printPostOrder();
  cout << endl;
}
