#include <iostream> // para escrever algo na linha de comando
using namespace std;

class Aluno {
  private:
    int ra;  // ra do aluno
    std::string nome;  // nome do aluno

  public:
    Aluno(); // construtor sem params, utilizado na locação dinâmica de memória
    Aluno(int ra, std::string nome);  // construtor para configurar o ra e nome
    string getNome() const;  // para obter nome
    int getRa() const;       // para obter ra
};