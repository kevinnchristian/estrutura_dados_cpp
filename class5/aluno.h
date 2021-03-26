#include <iostream>
using namespace std;

class Aluno{
private :
  int         ra;   // registro do aluno (RA)
  std::string nome; // nome do aluno 
public:  
  Aluno(); // Construtor vazio
  Aluno(int ra, std::string nome); // Construtor com params
  string getNome() const; // Método de pegar nome
  int getRa() const; // Método de pegar RA
};
