#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

class FilaCircular {
private:
    int* dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;

public:
    FilaCircular(int cap = 100);
    ~FilaCircular();

    bool estaVazia() const;
    bool estaCheia() const;
    bool inserir(int valor);
    bool remover(int &valor);
    bool consultarInicio(int &valor) const;
};

#endif
