#include <iostream>
#include <fstream>
#include "FilaCircular.h"

void mostrarMenu() {
    std::cout << "\n=== MENU FILA CIRCULAR ===\n";
    std::cout << "1. Inserir no fim da fila\n";
    std::cout << "2. Remover do início da fila\n";
    std::cout << "3. Consultar o início da fila\n";
    std::cout << "4. Verificar se a fila está vazia\n";
    std::cout << "5. Verificar se a fila está cheia\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opcao: ";
}

int main() {
    int capacidade;
    std::cout << "Digite a capacidade da fila: ";
    std::cin >> capacidade;

    FilaCircular fila(capacidade);

    std::ofstream logFile("log_fila.txt", std::ios::app); // abre para adicionar no final
    if (!logFile.is_open()) {
        std::cerr << "Erro ao abrir arquivo de log!\n";
        return 1;
    }

    int opcao;
    int valor;
    bool sucesso;

    do {
        mostrarMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Valor para inserir: ";
                std::cin >> valor;
                sucesso = fila.inserir(valor);
                if (sucesso) {
                    std::cout << "Valor inserido com sucesso.\n";
                    logFile << "Inserido: " << valor << "\n";
                } else {
                    std::cout << "Fila cheia! Nao foi possivel inserir.\n";
                    logFile << "Falha ao inserir " << valor << ": fila cheia\n";
                }
                break;

            case 2:
                sucesso = fila.remover(valor);
                if (sucesso) {
                    std::cout << "Valor removido: " << valor << "\n";
                    logFile << "Removido: " << valor << "\n";
                } else {
                    std::cout << "Fila vazia! Nada para remover.\n";
                    logFile << "Falha ao remover: fila vazia\n";
                }
                break;

            case 3:
                sucesso = fila.consultarInicio(valor);
                if (sucesso) {
                    std::cout << "Inicio da fila: " << valor << "\n";
                    logFile << "Consultado inicio: " << valor << "\n";
                } else {
                    std::cout << "Fila vazia! Nao ha inicio para consultar.\n";
                    logFile << "Falha ao consultar inicio: fila vazia\n";
                }
                break;

            case 4:
                if (fila.estaVazia()) {
                    std::cout << "Fila esta vazia.\n";
                    logFile << "Verificacao: fila esta vazia\n";
                } else {
                    std::cout << "Fila NAO esta vazia.\n";
                    logFile << "Verificacao: fila nao esta vazia\n";
                }
                break;

            case 5:
                if (fila.estaCheia()) {
                    std::cout << "Fila esta cheia.\n";
                    logFile << "Verificacao: fila esta cheia\n";
                } else {
                    std::cout << "Fila NAO esta cheia.\n";
                    logFile << "Verificacao: fila nao esta cheia\n";
                }
                break;

            case 0:
                std::cout << "Saindo...\n";
                logFile << "Programa finalizado pelo usuario.\n";
                break;

            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
                logFile << "Opcao invalida escolhida: " << opcao << "\n";
                break;
        }
    } while (opcao != 0);

    logFile.close();
    return 0;
}
