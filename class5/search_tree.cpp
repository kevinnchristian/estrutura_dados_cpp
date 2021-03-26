#include "search_tree.h"

// (*&) ponteiro com referência
void SearchTree::destroyTree(NodeType*& tree) // percorre a árvore inteira, desalocando NÓ a NÓ
{
  if (tree != NULL)
    {
      destroyTree(tree->esquerda);
      destroyTree(tree->direita);
      delete tree;
    }
}

bool SearchTree::isEmpty() const { // verifica se está apontando para nulo, que dizer não existe árvore 
  return root == NULL;
}
bool SearchTree::isFull() const {  // verifica se está cheio
  NodeType* location;
  try  // try catch evita de acontecer o erro e não ter resposta
    {
      location = new NodeType;
      delete location;
      return false;
    }
  catch(std::bad_alloc exception)  // o possível erro: bad_alloc
    {
      return true;
    }
}

void SearchTree::retrieveAluno(NodeType* tree, // método de busca
			       Aluno& aluno,
			       bool& found) const {
  if (tree == NULL)
    found = false;
  else if (aluno.getRa() < tree->aluno.getRa())
    retrieveAluno(tree->esquerda, aluno, found);
  else if (aluno.getRa() > tree->aluno.getRa())
    retrieveAluno(tree->direita, aluno, found);
  else {
    aluno = tree->aluno;
    found = true;
  }
}

void SearchTree::insertAluno(NodeType*& tree, Aluno aluno) // inserindo um novo aluno
{
  if (tree == NULL)
    {
      tree = new NodeType;
      tree->direita  = NULL;
      tree->esquerda = NULL;
      tree->aluno    = aluno;
    }
  else if (aluno.getRa() < tree->aluno.getRa() )
    insertAluno(tree->esquerda, aluno);
  else
    insertAluno(tree->direita, aluno);
}

void SearchTree::deleteAluno(NodeType*& tree, int aluno) // delete aluno, busca o NÓ que queremos remover
{
  if (aluno < tree->aluno.getRa() )
    deleteAluno(tree->esquerda, aluno);
  else if (aluno > tree->aluno.getRa() )
    deleteAluno(tree->direita, aluno); 
  else if (aluno == tree->aluno.getRa())
    deleteNode(tree);
}

void SearchTree::deleteNode(NodeType*& tree) {  // delete NÓ, busca a árvore que queremos remover 
  Aluno data;
  NodeType* tempPtr;
  tempPtr = tree;
  if (tree->esquerda == NULL) {
    tree = tree->direita;
    delete tempPtr;
  }
  else if (tree->direita == NULL) {
    tree = tree->esquerda;
    delete tempPtr;
  }
  else {
    getSuccessor(tree, data);  // usando a busca pelo sucessor lógico
    tree->aluno = data;
    deleteAluno(tree->direita, data.getRa());
  }
}

void SearchTree::getSuccessor(NodeType* tree, Aluno& data) // pega sucessor lógico
{
  tree = tree->direita;  // vai para direita
  while (tree->esquerda != NULL) // depois para esquerda até chegar ao fim
    tree = tree->esquerda;
  data = tree->aluno;
}

void SearchTree::printPreOrder(NodeType* tree) const {  // imprimindo árvore seguindo a regras de pré-ordem
  if (tree != NULL) {
      std::cout << tree->aluno.getNome() << " , ";
      printPreOrder(tree->esquerda);
      printPreOrder(tree->direita);
    }
}

void SearchTree::printInOrder(NodeType* tree) const { // imprimindo árvore seguindo a regras de in-ordem
  if (tree != NULL) {
	printInOrder(tree->esquerda);
	std::cout << tree->aluno.getNome() << " , ";
	printInOrder(tree->direita);
    }
}
void SearchTree::printPostOrder(NodeType* tree) const { // imprimindo árvore seguindo a regras de pós-ordem
  if (tree != NULL) {
	printPostOrder(tree->esquerda);
	printPostOrder(tree->direita);
	std::cout << tree->aluno.getNome() << " , ";
    }
}
