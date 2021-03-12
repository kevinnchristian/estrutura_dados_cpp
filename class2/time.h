// As primeiras linhas de código deste arquivo servem para evitar que múltiplas
// definições da classe Time ocorram. Isso poderia ocorrer se você der include
// de dois pacotes que dão include em [time.h]

#ifndef TIME_H  // Inclua esse bloco apenas se TIME_H não está definido
#define TIME_H  // Na primeira inclusão, defina TIME_H para que este bloco não
                // seja incluído mais de uma vez

class Time { // Nome da Classe
  private:   // Seção Privada, definição dos atributos
    int hour;    // 0 - 23
    int minute;  // 0 - 59
    int second;  // 0 - 59

  public:    // Seção Pública, usuário tem acesso
    Time (int hour = 0, int minute = 0, int second = 0); // Construtor, onde a pessoa pode informa o que deseja...caso se não for informado nada o default será 0 
    int getHour() const;                      
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);
    int getSecond() const;
    void setSecond(int second);
    void print() const;
    void nextSecond();
};

#endif  // Precisa para fechar o #ifndef