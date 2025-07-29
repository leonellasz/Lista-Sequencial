#include <iostream>
#include <cassert>
#include "FilaCircular.h"

void testarFila() {
    FilaCircular fila(3);

    // Testar fila vazia
    assert(fila.estaVazia() == true);
    assert(fila.estaCheia() == false);

    // Inserir elementos
    assert(fila.inserir(1) == true);
    assert(fila.inserir(2) == true);
    assert(fila.inserir(3) == true);

    // Fila deve estar cheia agora
    assert(fila.estaCheia() == true);
    assert(fila.inserir(4) == false);  // Não pode inserir mais

    // Consultar início
    int valor;
    assert(fila.consultarInicio(valor) == true);
    assert(valor == 1);

    // Remover elementos
    assert(fila.remover(valor) == true);
    assert(valor == 1);
    assert(fila.remover(valor) == true);
    assert(valor == 2);
    assert(fila.remover(valor) == true);
    assert(valor == 3);

    // Fila deve estar vazia
    assert(fila.estaVazia() == true);
    assert(fila.remover(valor) == false);  // Nada para remover

    std::cout << "Todos os testes passaram com sucesso!" << std::endl;
}

int main() {
    testarFila();
    return 0;
}
