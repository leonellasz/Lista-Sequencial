#include "FilaCircular.h"

FilaCircular::FilaCircular(int cap) {
    capacidade = cap;
    dados = new int[capacidade];
    inicio = 0;
    fim = 0;
    tamanho = 0;
}

FilaCircular::~FilaCircular() {
    delete[] dados;
}

bool FilaCircular::estaVazia() const {
    return tamanho == 0;
}

bool FilaCircular::estaCheia() const {
    return tamanho == capacidade;
}

bool FilaCircular::inserir(int valor) {
    if (estaCheia()) return false;
    dados[fim] = valor;
    fim = (fim + 1) % capacidade;
    tamanho++;
    return true;
}

bool FilaCircular::remover(int &valor) {
    if (estaVazia()) return false;
    valor = dados[inicio];
    inicio = (inicio + 1) % capacidade;
    tamanho--;
    return true;
}

bool FilaCircular::consultarInicio(int &valor) const {
    if (estaVazia()) return false;
    valor = dados[inicio];
    return true;
}
