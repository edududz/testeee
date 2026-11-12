#include "Dijkstra.hpp"

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>

namespace {
double obterPeso(const Aresta& aresta, Criterio criterio) {
    switch (criterio) {
        case Criterio::CUSTO:     return aresta.custo;
        case Criterio::DISTANCIA: return aresta.distancia;
        case Criterio::TEMPO:     return aresta.tempo;
    }
    return std::numeric_limits<double>::infinity();
}

const char* nomeCriterio(Criterio criterio) {
    switch (criterio) {
        case Criterio::CUSTO:     return "MENOR CUSTO";
        case Criterio::DISTANCIA: return "MENOR DISTANCIA";
        case Criterio::TEMPO:     return "MENOR TEMPO";
    }
    return "CRITERIO";
}

const char* unidade(Criterio criterio) {
    switch (criterio) {
        case Criterio::CUSTO:     return "R$";
        case Criterio::DISTANCIA: return "km";
        case Criterio::TEMPO:     return "horas";
    }
    return "";
}
}

ResultadoDijkstra dijkstra(const Grafo& grafo,
                           int origem,
                           int destino,
                           Criterio criterio) {
    const int n = grafo.quantidadeVertices();

    if (origem < 0 || destino < 0 || origem >= n || destino >= n) {
        throw std::out_of_range("Origem ou destino fora dos limites do grafo.");
    }

    const double INF = std::numeric_limits<double>::infinity();
    std::vector<double> distancias(n, INF);
    std::vector<int> anterior(n, -1);

    // Fila de prioridade: sempre processa primeiro o menor custo acumulado.
    using Estado = std::pair<double, int>;
    std::priority_queue<Estado, std::vector<Estado>,
                        std::greater<Estado>> fila;

    distancias[origem] = 0.0;
    fila.push({0.0, origem});

    while (!fila.empty()) {
        const auto [distAtual, atual] = fila.top();
        fila.pop();

        // Ignora entradas antigas da fila.
        if (distAtual > distancias[atual]) {
            continue;
        }

        if (atual == destino) {
            break;
        }

        for (const Aresta& aresta : grafo.adj[atual]) {
            const double peso = obterPeso(aresta, criterio);

            if (peso < 0.0) {
                throw std::invalid_argument(
                    "Dijkstra nao aceita pesos negativos nas arestas.");
            }

            const double novaDistancia = distancias[atual] + peso;

            if (novaDistancia < distancias[aresta.destino]) {
                distancias[aresta.destino] = novaDistancia;
                anterior[aresta.destino] = atual;
                fila.push({novaDistancia, aresta.destino});
            }
        }
    }

    ResultadoDijkstra resultado;

    if (distancias[destino] == INF) {
        return resultado; // destino não alcançável
    }

    resultado.existeCaminho = true;
    resultado.total = distancias[destino];

    // Reconstrói o caminho voltando do destino até a origem.
    for (int atual = destino; atual != -1; atual = anterior[atual]) {
        resultado.caminho.push_back(atual);
        if (atual == origem) {
            break;
        }
    }

    // Se não chegou à origem, não há caminho válido reconstruível.
    if (resultado.caminho.empty() || resultado.caminho.back() != origem) {
        resultado.existeCaminho = false;
        resultado.caminho.clear();
        resultado.total = 0.0;
        return resultado;
    }

    std::reverse(resultado.caminho.begin(), resultado.caminho.end());
    return resultado;
}

void exibirResultado(const Grafo& grafo,
                     const ResultadoDijkstra& resultado,
                     Criterio criterio,
                     const std::string& nomeOrigem,
                     const std::string& nomeDestino) {
    std::cout << "\n=== " << nomeCriterio(criterio) << " ===\n";

    if (!resultado.existeCaminho) {
        std::cout << "Nao existe caminho entre "
                  << nomeOrigem << " e " << nomeDestino << ".\n";
        return;
    }

    std::cout << "Rota: ";
    for (std::size_t i = 0; i < resultado.caminho.size(); ++i) {
        int indice = resultado.caminho[i];
        std::cout << grafo.vertices[indice];
        if (i + 1 < resultado.caminho.size()) {
            std::cout << " -> ";
        }
    }

    std::cout << "\nTotal: " << std::fixed << std::setprecision(2)
              << resultado.total << " " << unidade(criterio) << "\n";
}

void executarTresCriterios(const Grafo& grafo,
                           int origem,
                           int destino) {
    if (origem < 0 || destino < 0 ||
        origem >= grafo.quantidadeVertices() ||
        destino >= grafo.quantidadeVertices()) {
        throw std::out_of_range("Origem ou destino invalido.");
    }

    const std::string& nomeOrigem = grafo.vertices[origem];
    const std::string& nomeDestino = grafo.vertices[destino];

    ResultadoDijkstra porCusto =
        dijkstra(grafo, origem, destino, Criterio::CUSTO);
    ResultadoDijkstra porDistancia =
        dijkstra(grafo, origem, destino, Criterio::DISTANCIA);
    ResultadoDijkstra porTempo =
        dijkstra(grafo, origem, destino, Criterio::TEMPO);

    exibirResultado(grafo, porCusto, Criterio::CUSTO,
                    nomeOrigem, nomeDestino);
    exibirResultado(grafo, porDistancia, Criterio::DISTANCIA,
                    nomeOrigem, nomeDestino);
    exibirResultado(grafo, porTempo, Criterio::TEMPO,
                    nomeOrigem, nomeDestino);
}
