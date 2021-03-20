#include <iostream>
#include "hash.h" 

using namespace std;

int main(){
  Hash alunosHash(10); // criando vetor de 10 elmentos
   int   ras[7]   = {  // ra's do aluno
     12704, 31300, 1234,
     49001, 52202, 65606,
     91234};
  string nomes[7] = {  // nome dos alunos
    "Pedro", "Raul", "Paulo",
    "Carlos", "Lucas", "Maria",
    "Samanta"}; 
	    
  for (int i = 0; i < 7; i++) { // iterando nos RA's e Nomes e está dando um insertItem na tabela hash
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunosHash.insertItem(aluno);
  }
  alunosHash.print();  // print para saber onde está cada aluno dentro do vetor
  cout << "------------------------------" <<  endl;
  
  Aluno aluno(12704,"");  // criei este aluno
  bool     found = false; // falando que ele é false/não_existe
  alunosHash.retrieveItem(aluno, found); // procurou por esse aluno
  cout << aluno.getNome() << " -> " << found << endl; // verifica oq foi retornado, aqui ele traz 0 no found por que ele não existe
  
  cout << "------------------------------" <<  endl;

  alunosHash.deleteItem(aluno); // Deletou o aluno 12704, e como esse cara aponta para indice 4 ele acaba apagando 
  alunosHash.print();           // a Samanta, dado que aqui neste momento não tem verificação de colisão
  cout << "Fim" << endl;  
}
