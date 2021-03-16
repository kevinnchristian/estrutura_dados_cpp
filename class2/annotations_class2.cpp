// -> CLASSES

// -> Visão lógica de uma classe será sempre criada em um arquivo com a extensão [.h]
//      - Nesse arquivos iremos definir os [MEMBROS PÚBLICOS e PRIVADOS] de uma classe

// -> [IMPLEMENTAÇÃO da CLASSE] será sempre feita em um arquivo com extensão [.cpp]
//      - Esse arquivo [.cpp] deverá sempre importar o arquivo [.h] com a diretiva [include]

// -> Operador [::] de [resolução de escopo]
//      - Ele vai parear a [CLASS] com a [IMPLEMENTAÇÃO(time.cpp)]

// -> Neste caso como [COMPILAR]
//      - Temos arquivos [.h] e [.cpp]
//      - Passamos para o compilador apenas os arquivos de impletação os [.cpp]
//          > g++ time.cpp time_main.cpp -o time
//                         ou
//          > g++ *.cpp, gera um arquivo para executar [a.out]
//          > executa ./time ou ./a.out
//

