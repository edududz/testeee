#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Grafo.hpp"
#include <string>
#include <vector>

enum class Criterio {
    CUSTO,
    DISTANCIA,
    TEMPO
};

struct ResultadoDijkstra {
    bool existeCaminho = false;
    double total = 0.0;
    std::vector<int> caminho; // índices dos vértices, da origem ao destino
};

// Calcula o menor caminho da origem até o destino usando o peso escolhido.
ResultadoDijkstra dijkstra(const Grafo& grafo,
                           int origem,
                           int destino,
                           Criterio criterio);

// Exibe o caminho e o total com a unidade correspondente.
void exibirResultado(const Grafo& grafo,
                     const ResultadoDijkstra& resultado,
                     Criterio criterio,
                     const std::string& nomeOrigem,
                     const std::string& nomeDestino);

// Executa Dijkstra três vezes: custo, distância e tempo.
void executarTresCriterios(const Grafo& grafo,
                           int origem,
                           int destino);

#endif
