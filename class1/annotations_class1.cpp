// -> Compila o código criado:
//      > g++ hello_world.cpp -o hello_world
//
// -> Executar o código: 
//      > ./hello_world 
//
// -> os PARAMS das FUNÇÕES podem ser passados por VALOR ou REFERÊNCIA:
//      > VALOR: cópia da variável, alterações dentro da função não afeta o valor da variável
//      > REFERÊNCIA: referência a variável e não a cópia, alterações dentro da
//        função afeta o valor da variável
//
//
// -> Ponteiros:
//      > tipo *ponteiro
//      > ex: int* intPointer
//      > * na direita ou esquerda não muda nada, vai continuar sendo ponteiro
//
//      > INICIALIZAÇÂO DE PONTEIROS:
//        - Operador (&) permite obter o endereç de memória de uma variável, de forma ESTÁTICA
//        - ex: intPointer = &alpha
//
//        - Operador (new) e (delete) para alocar e desalocar memória, de forma DINÂMICA
//        - intPointer = new int;
//        - delete intPointer;
//        -Obs.: O DELETE não inutiliza a variável ponteiro, apenas libera a região que ela aponta
//
//      > UTILIZAÇÂO DE MEMÒRIA:
//        - Operador (*) é uma operador UNÀRIO que retorna o conteúdo da variável
//          localizada no endereço especificado
//        - anotherInt = *intPointer;
//
//      > Ponteiro que aponta para valor VAZIO, utilizaremos NULL
//        - Esta dentro da lib <cstddef>
//
//
// -> Vetores:
//      > tipo nomeDoVetor[tamanho_vetor]
//      > int c[10]; - declarar SEM atribuição
//      > int c[10] = {14, 0, 13}; - declarar e incializando COM atribuição
//      > int c[] = {14, 0, 13}; - declarar e incializar COM atribuição sem definir o TAMANHO do VETOR, adota o VALOR de ELEMENTOS para o seu TAMANHO
//      > Podemos também incializar dentro de um for: vetorX[] = n*indice, por exemplo
//
//      > ALOCAÇÂO DINÂMICA com VETORES:
//        - int* c = new int[num_elementos];
//        - DESALOCAÇÂO deste VETOR: delete [] c;